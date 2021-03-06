#ifndef SHAPE3D_H_
#define SHAPE3D_H_

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include "vec3d.h"
#include "src/Mesh/mesh.h"
#include "src/Mesh/blockMesh.h"
#include <vector>
#include <string>

enum class Type{
	AIR = 100,
	GRASS_TOP = 0,
	GRASS_SIDE = 1,
	GRASS_BOT = 2,
};

class Shape3D {

protected:

	std::vector<Vertex> vertices;
	std::vector<Block> verticesArray;
	std::vector<unsigned int> indices;
	std::vector<Texture> textures;

	Shape3D();

public:

	std::vector<Vertex> getVertices();
	std::vector<unsigned int> getIndices();
	std::vector<Texture> getTextures();
	void addTexture(const char *path);
	Mesh createMesh();

};

#endif
