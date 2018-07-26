#ifndef CHUNKMANAGER_H_
#define CHUNKMANAGER_H_

#include <vector>
#include <memory>

#include "blockChunk.h"
#include "heightChunk.h"
#include "../Renderer/chunkRenderer.h"
#include "../../src/Mesh/mesh.h"
#include "../../src/utility/threadPool.h"
#include "../../vec3d.h"

class ChunkManager{
  // Need 3 dimensional chunks
  std::vector<std::vector<std::vector<BlockChunk>>> m_chunks;
  std::vector<std::vector<std::shared_ptr<HeightChunk>>> m_heightChunks;

  std::vector<ChunkMesh*> renderList;
  int M_WIDTH;
  int M_HEIGHT;
  int M_LENGTH;

  int centerX;
  int centerY;

  bool isHeightReady;
  bool isChunkReady;
  bool isProcessing;
  bool isProcessing2;
  bool isNeedUpdate;

  void initializeHeights();
  bool shouldAddFace(int chunkX, int chunkY, int chunkZ);

public:
  ChunkManager(int width, int length);
  ChunkManager(int width, int length, std::vector<int> heights);
  void draw(ChunkRenderer renderer);
  void addHeight(std::vector<int> heights);
  const std::vector<std::vector<std::vector<BlockChunk>>> getChunks();
  void initMesh();
  void initHeight();
  void addChunks();
  void generateChunkMesh(int chunkX, int chunkY, int chunkZ);

  // Used to load and unload height chunks
  void moveFront();
  void moveBack();
  void moveLeft();
  void moveRight();

};
#endif
