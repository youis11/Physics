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

	// TODO 2: Chain few N spheres together to form a snake
	//s_snake[0].SetPos(0, 0, 0);
	//s_snake[1].SetPos(1, 2, 0);
	//s_snake[2].SetPos(2, 3, 0);
	//s_snake[3].SetPos(3, 4, 0);
	//s_snake[4].SetPos(4, 5, 0);
	//s_snake[5].SetPos(5, 6, 0);
	//s_snake[6].SetPos(6, 7, 0);
	//s_snake[7].SetPos(7, 8, 0);

	//pb_snake[0] = App->physics->AddBody(s_snake[0]);
	//pb_snake[1] = App->physics->AddBody(s_snake[1]);
	//pb_snake[2] = App->physics->AddBody(s_snake[2]);
	//pb_snake[3] = App->physics->AddBody(s_snake[3]);
	//pb_snake[4] = App->physics->AddBody(s_snake[4]);
	//pb_snake[5] = App->physics->AddBody(s_snake[5]);
	//pb_snake[6] = App->physics->AddBody(s_snake[6]);
	//pb_snake[7] = App->physics->AddBody(s_snake[7]);

	//vec3 pivotA{ 3, 4, 3 };
	//vec3 pivotB{ 3, 4, 3 };

	//App->physics->AddConstraintP2P(*pb_snake[0], *pb_snake[1], pivotA, pivotB);
	//App->physics->AddConstraintP2P(*pb_snake[1], *pb_snake[2], pivotA, pivotB);
	//App->physics->AddConstraintP2P(*pb_snake[2], *pb_snake[3], pivotA, pivotB);
	//App->physics->AddConstraintP2P(*pb_snake[3], *pb_snake[4], pivotA, pivotB);
	//App->physics->AddConstraintP2P(*pb_snake[4], *pb_snake[5], pivotA, pivotB);
	//App->physics->AddConstraintP2P(*pb_snake[5], *pb_snake[6], pivotA, pivotB);
	//App->physics->AddConstraintP2P(*pb_snake[6], *pb_snake[7], pivotA, pivotB);

	// TODO 4: Chain few N spheres together to form a a bike's sphere
	// Be sure to put the right axis
	/*App->physics->AddConstraintHinge(pb_snake2*, s_snake2*, );*/

	s_snake[0].SetPos(0, 0, 0);
	s_snake[1].SetPos(1, 2, 0);
	s_snake[2].SetPos(2, 3, 0);
	s_snake[3].SetPos(3, 4, 0);
	s_snake[4].SetPos(4, 5, 0);
	s_snake[5].SetPos(5, 6, 0);
	s_snake[6].SetPos(6, 7, 0);
	s_snake[7].SetPos(7, 8, 0);

	pb_snake[0] = App->physics->AddBody(s_snake[0]);
	pb_snake[1] = App->physics->AddBody(s_snake[1]);
	pb_snake[2] = App->physics->AddBody(s_snake[2]);
	pb_snake[3] = App->physics->AddBody(s_snake[3]);
	pb_snake[4] = App->physics->AddBody(s_snake[4]);
	pb_snake[5] = App->physics->AddBody(s_snake[5]);
	pb_snake[6] = App->physics->AddBody(s_snake[6]);
	pb_snake[7] = App->physics->AddBody(s_snake[7]);

	vec3 pivotA{ 3, 4, 3 };
	vec3 pivotB{ 3, 4, 3 };
	vec3 axisA{ 0,0,0 };
	vec3 axisB{ 1,1,1 };

	App->physics->AddConstraintHinge(*pb_snake[0], *pb_snake[1], pivotA, pivotB, axisA, axisB);
	App->physics->AddConstraintHinge(*pb_snake[1], *pb_snake[2], pivotA, pivotB, axisA, axisB);
	App->physics->AddConstraintHinge(*pb_snake[2], *pb_snake[3], pivotA, pivotB, axisA, axisB);
	App->physics->AddConstraintHinge(*pb_snake[3], *pb_snake[4], pivotA, pivotB, axisA, axisB);
	App->physics->AddConstraintHinge(*pb_snake[4], *pb_snake[5], pivotA, pivotB, axisA, axisB);
	App->physics->AddConstraintHinge(*pb_snake[5], *pb_snake[6], pivotA, pivotB, axisA, axisB);
	App->physics->AddConstraintHinge(*pb_snake[6], *pb_snake[7], pivotA, pivotB, axisA, axisB);

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

	/* Uncomment when ready
	for(int i = 0; i < MAX_SNAKE; ++i)
	{
		pb_snake[i]->GetTransform(&(s_snake[i].transform));
		s_snake[i].Render();
	}

	for(int i = 0; i < MAX_SNAKE; ++i)
	{
		pb_snake2[i]->GetTransform(&(s_snake2[i].transform));
		s_snake2[i].Render();
	}*/

	return UPDATE_CONTINUE;
}

void ModuleSceneIntro::OnCollision(PhysBody3D* body1, PhysBody3D* body2)
{
}

