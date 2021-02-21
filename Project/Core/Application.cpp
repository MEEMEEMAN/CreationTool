//
// Created by PERHAPS-MACHINE on 2/20/2021.
//
#include "Application.h"
#include "CreationCore.h"
#include <string>
#include "SDL.h"

#if EDITOR_TOOLS

#endif

#if WIN32

#include "glad/glad.h"

#elif ANDROID
#include <GLES3/gl31.h>
#include <GLES3/gl3platform.h>
#endif

namespace CT {

    SDL_Window *InitSDLWindow(const char *title) {
        if (SDL_Init(SDL_INIT_VIDEO) < 0) {
            conlog("Failed to init SDL!");
            exit(ExitCodes::SDL_CONTEXT_FAIL_INIT);
        }

        int major, minor;
        SDL_GLprofile profile;

        SDL_DisplayMode screenData;
        SDL_GetDisplayMode(0, 0, &screenData);
        int screenWidth = screenData.w, screenHeight = screenData.h;

#if WIN32 //use OpenGL 4.3
        major = 4;
        minor = 3;
        profile = SDL_GL_CONTEXT_PROFILE_CORE;

        screenWidth = 1280;
        screenHeight = 720;
#elif ANDROID //use OpenGL ES 3.1
        major = 3;
        minor = 1;
        profile = SDL_GL_CONTEXT_PROFILE_ES;
#endif

        SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, profile);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, major);
        SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, minor);
        SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);


        uint32_t flags = SDL_RENDERER_ACCELERATED | SDL_WINDOW_OPENGL;
        if (Application::IsMobile())
            flags |= SDL_WINDOW_FULLSCREEN;

        SDL_Window *window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                                              screenWidth, screenHeight, flags);

        if (window == nullptr) {
            conlog("Failed to create an SDL window!");
            exit(ExitCodes::SDL_WINDOW_FAIL_CREATE);
        }

        SDL_GLContext glContext = SDL_GL_CreateContext(window);

#if WIN32
        if (!gladLoadGLLoader((GLADloadproc) SDL_GL_GetProcAddress)) {
            conlog("Failed to initialize Glad!");
            exit(ExitCodes::GL_GRAPHICS_FAIL_INIT);
        }
#endif

        SDL_Log("Created opengl context and window at resolution: %ix%i", screenWidth, screenHeight);
        SDL_Log("%s using %s", glGetString(GL_SHADING_LANGUAGE_VERSION), glGetString(GL_RENDERER));
        return window;
    }

    const char *vertexShaderSource = "#version 300 es\n"
                                     "layout (location = 0) in vec3 aPos;\n"
                                     "void main()\n"
                                     "{\n"
                                     "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
                                     "}\0";
    const char *fragmentShaderSource = "#version 300 es\n"
                                       "out vec4 FragColor;\n"
                                       "void main()\n"
                                       "{\n"
                                       "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
                                       "}\n\0";

    void Application::Initialize(int argc, char *argv[]) {
        mainWindow = InitSDLWindow("CreationTool in action");

        unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
        glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
        glCompileShader(vertexShader);
        // check for shader compile errors
        int success;
        char infoLog[512];
        glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
        if (!success) {
            glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);

            conlog("Vertex shader failed to compile!");
        }
        // fragment shader
        unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
        glCompileShader(fragmentShader);
        // check for shader compile errors
        glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
        if (!success) {
            glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
            conlog("Fragment shader failed to compile!");
        }
        // link shaders
        unsigned int shaderProgram = glCreateProgram();
        glAttachShader(shaderProgram, vertexShader);
        glAttachShader(shaderProgram, fragmentShader);
        glLinkProgram(shaderProgram);
        // check for linking errors
        glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
        if (!success) {
            glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
            conlog("Shader linking failed!");
        }
        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);

        // set up vertex data (and buffer(s)) and configure vertex attributes
        // ------------------------------------------------------------------
        float vertices[] = {
                0.5f, 0.5f, 0.0f,  // top right
                0.5f, -0.5f, 0.0f,  // bottom right
                -0.5f, -0.5f, 0.0f,  // bottom left
                -0.5f, 0.5f, 0.0f   // top left
        };
        unsigned int indices[] = {  // note that we start from 0!
                0, 1, 3,  // first Triangle
                1, 2, 3   // second Triangle
        };
        unsigned int VBO, VAO, EBO;
        glGenVertexArrays(1, &VAO);
        glGenBuffers(1, &VBO);
        glGenBuffers(1, &EBO);
        // bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
        glBindVertexArray(VAO);

        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void *) 0);
        glEnableVertexAttribArray(0);

        SDL_Event sdlEvent;
        while (!shouldQuit) {
            while (SDL_PollEvent(&sdlEvent) != 0) {
                switch (sdlEvent.type) {
                    case SDL_KEYDOWN:
                        conlog("Key Down!");
                        break;
                    case SDL_QUIT:
                        shouldQuit = true;
                        break;
                }
            }
            glClearColor(0, 0, 1, 1);
            glClear(GL_COLOR_BUFFER_BIT);

            glUseProgram(shaderProgram);
            glBindVertexArray(VAO);
            glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

            SDL_GL_SwapWindow(mainWindow);
        }
    }

    void Application::Stop() {
        shouldQuit = true;
    }

    constexpr bool Application::IsMobile() {
#ifdef WIN32
        return false;
#else
        return true;
#endif
    }

    constexpr bool Application::IsEditor() {
#ifdef EDITOR_TOOLS
        return true;
#endif
        return false;
    }
}