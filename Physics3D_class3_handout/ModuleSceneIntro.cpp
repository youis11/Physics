#include "Globals.h"
#include "Application.h"
#include "ModuleSceneIntro.h"
#include "Primitive.h"
#include "PhysBody3D.h"

ModuleSceneIntro::ModuleSceneIntro(Application* app, bool start_enabled) : Module(app, start_enabled)
{
}

ModuleSceneIntro::~ModuleSceneIntro()
{}

// Load assets
bool ModuleSceneIntro::Start()
{
	LOG("Loading Intro assets");
	bool ret = true;

	App->camera->Move(vec3(1.0f, 1.0f, 0.0f));
	App->camera->LookAt(vec3(0, 0, 0));

	// TODO 3: create a sphere in the world with a primitive
	// and create a physics body for it. Remember to render it in Update()

	sphere.radius = 3;
	sphere.axis = true;
	sphere.SetPos(0, 10, 0);
	b = App->physics->AddBody(sphere,1);

	// TODO 5: Add this module to the list of collision listeners
	
	return ret;
}

// Load assets
bool ModuleSceneIntro::CleanUp()
{
	LOG("Unloading Intro scene");

	return true;
}

// Update
update_status ModuleSceneIntro::Update(float dt)
{
	Plane p(0, 1, 0, 0);
	p.axis = true;
	p.Render();

	sphere.Render();
	// TODO 4: update the transform of the shape to meet the
	// physics one

	//mat4x4 matrix;
	//matrix.translate();
	//
	//btTransform startTransform;
	//startTransform.setFromOpenGLMatrix(&matrix);

	//b->GetTransform(matrix);

	return UPDATE_CONTINUE;
}

// TODO 5: ... and define it for the ModuleScenario. Set the ball
// in red if it happens using is color property
void ModuleSceneIntro::OnCollision(PhysBody3D* body1, PhysBody3D* body2) {
	int x, y;
	sphere.color.Set(255, 0, 0);
}


