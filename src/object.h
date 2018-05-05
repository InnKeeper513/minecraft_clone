#ifndef OBJECT_H_
#define OBJECT_H_

#include "math/vec3d.h"
#include <vector>
#include "force.h"

using namespace std;

class Object{

	Vec3D position;
	double mass;
	double inverseMass;
	std::vector<Force> forces;
	std::vector<Force> continuousForces;
	Vec3D acceleration;
	Vec3D velocity;
	double damping;

	public:

	Object();
	Object(double x,double y,double z);
	
	void setMass(double mass);
	void setInverseMass(double inverseMass);
	std::vector<Force> getForce();
	void addForce(Force force);
	void addContinuousForce(Force force);
	void clearForce();
	void setPosition(double x, double y, double z);
	void setPosition(Vec3D vec);
	double getMass();
	double getInverseMass();
	Vec3D getPosition();
	void setAcceleration(Vec3D acceleration);
	Vec3D getAcceleration();
	void setVelocity(Vec3D velocity);
	Vec3D getVelocity();
	void setDamping(double damping);
	double getDamping();
	void update(double time);
	

};


#endif
