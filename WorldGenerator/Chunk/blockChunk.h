#ifndef WORLDGENERATOR_CHUNK_BLOCKCHUNK_H_
#define WORLDGENERATOR_CHUNK_BLOCKCHUNK_H_

#include <mutex>

#include <vector>

#include "../TypeGen/typeGen.h"
#include "../blockInfo.h"
#include "../../Vec3D.h"
#include "../../shader.h"
#include "../../src/Mesh/chunkMesh.h"
#include "../Renderer/direction.h"
#include "../Renderer/chunkRenderer.h"
#include "../Resource/textureManager.h"
#include "../Block/blockTextures.h"

class BlockChunk{

  std::vector<std::vector<std::vector<BlockInfo>>> blocks;
  std::vector<std::vector<int>> highest;

  int initWidth;
  int initLength;
  int initHeight;

  int indiceCount = 0;
  bool isActive = false;
  bool isReady = false;

  std::shared_ptr<ChunkMesh> mesh;
  bool needUpdate = true;
  std::vector<int> textureIndexes;
  std::vector<Vec2D> textureCoordinates;
  std::vector<Vec3D> vertices;
  std::vector<Vec3D> normals;

  std::vector<int> indices;
  std::vector<int> m_hightest;

public:
  BlockChunk();
  ~BlockChunk();
  // Feed in Block Chunk size of height data, and block chunk will build the coords
  BlockChunk(int width, int height, int length, std::vector<int> heights, std::vector<int> actualheight);
  // Fill all blocks
  BlockChunk(int width, int height, int length);
  std::vector<std::vector<int>>& getHighest();

  void setConfig(int width, int height, int length);
  void setIsActive(bool isActive);
  bool getIsActive();

  void setIsReady(bool isReady);
  bool getIsReady();

  std::vector<std::vector<std::vector<BlockInfo>>>& getBlockInfo();
  void addHeight(int width, int height, int length);
  void updateMesh();
  void setUpdate(bool status);
  void rebuildMesh();

  // Set the block type of a block
  void setType(int x, int y, int z, BLOCKTYPE type);

  // Add a face by specifying a direction
  void addFace(int i, int j, int k, Direction direction);
  int getVerticeCount();
  std::shared_ptr<ChunkMesh> getMesh();
  void clear();

  bool canRender();
};
#endif
