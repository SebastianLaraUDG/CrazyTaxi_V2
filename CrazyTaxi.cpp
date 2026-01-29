#include "raylib.h"
#include "raymath.h"
#include <ode/ode.h>

static void HandleResizingWindow(int& screenWidth, int& screenHeight)
{
    if (IsWindowResized() && !IsWindowFullscreen())
    {
        screenWidth = GetScreenWidth();
        screenHeight = GetScreenHeight();
    }

    // check for alt + enter
    if (IsKeyPressed(KEY_ENTER) && (IsKeyDown(KEY_LEFT_ALT) || IsKeyDown(KEY_RIGHT_ALT)))
    {
        // see what display we are on right now
        int display = GetCurrentMonitor();


        if (IsWindowFullscreen())
        {
            // if we are full screen, then go back to the windowed size
            SetWindowSize(screenWidth, screenHeight);
        }
        else
        {
            // if we are not full screen, set the window size to match the monitor we are on
            SetWindowSize(GetMonitorWidth(display), GetMonitorHeight(display));
        }

        // toggle the state
        ToggleFullscreen();
    }

}


class NivelJugable
{
public:
    void Init();

private:
    Camera camera;
};
void NivelJugable::Init()
{
    camera = { 0 };
    camera.position = { 0.0f, 5.0f, -10.0f };
    // camOffset = { 0.0f, 5.0f, -10.0f };
    camera.target = { 0.0f, 0.0f, 0.0f };
    camera.up = { 0.0f, 1.0f, 0.0f };
    camera.fovy = 45.0f;
    camera.projection = CAMERA_PERSPECTIVE;
}

#include <unordered_map>
class ODEManager
{
public:
    void Init();
    void DeInit();
private:
    dWorldID world_;
    dSpaceID space_;

    // All bodies in the current world
    std::unordered_map<uint32_t, dGeomID> bodies_;
    std::unordered_map<uint32_t, dBodyID> physicsBodies_;
};

void ODEManager::Init()
{
    dInitODE2(0);
    world_ = dWorldCreate();
    space_ = dSimpleSpaceCreate(0);

    dWorldSetGravity(world_, 0, 0, -9.81);
    dWorldSetAngularDamping(world_, 0.15); // Random value, can be modified.
    physicsBodies_[0] = dBodyCreate(world_);


}

int main(void)
{
    int screenWindow = 800, screenHeight = 600;

    // Enable resizing window.
    SetConfigFlags(FLAG_WINDOW_RESIZABLE | FLAG_VSYNC_HINT);

    InitWindow(screenWindow, screenHeight, "raylib");

    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        HandleResizingWindow(screenWindow, screenHeight);

        BeginDrawing();
        ClearBackground(RAYWHITE);

        // Draw here.


        EndDrawing();
    }
    CloseWindow();
    return 0;
}