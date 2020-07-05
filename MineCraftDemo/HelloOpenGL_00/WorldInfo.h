#pragma once
#include <glm/glm.hpp>
#include <glm/vec4.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <queue>
#include "Point.h"
#include <thread>
#include <future>
class World;
using namespace std;
struct ChunkGenTask {
	float dis;
	Point3 point;
	ChunkGenTask(float _dis, Point3 _point) : dis(_dis), point(_point) {}
	bool operator < (ChunkGenTask const &a) const {
		return dis > a.dis;
	}
};

class WorldInfo
{
public:
	WorldInfo();
	~WorldInfo();
	//static std::thread t;
	static priority_queue<ChunkGenTask> chunkGenTaskPriorityQueue;
	//��Ⱦ����
	static bool useLight; //ʹ�ù�����
	static bool useFog; //ʹ����Ч��
	static glm::mat4 projection;
	static glm::mat4 view;
	static glm::vec3 lastUpdatePostion;  //�ϴθ���chunkʱ����λ��
	static float maxUpdateIntervalDis; //�ƶ��˶��ľ����Ҫ������
	static float renderRadius;  //��Ⱦ����
	static int renderChunkRadius;  //
	static int chunkSize; //ÿ��chunk�г����ж��ٸ�block
	static int chunkHeight;
	//���ղ���
	static glm::vec3 lightPos;
	static glm::vec3 ambient;
	static glm::vec3 diffuse;
	static glm::vec3 specular;
	//�����
	static float fogMaxDist;
	static float fogMinDist;
	static glm::vec4 fogColor;
	//ˮ����
	static float waterLevel;  //ˮƽ��
	static glm::vec4 WorldInfo::waterColor;
	static float waterViewMaxDist;  //��ˮ����Զ�ɼ�
	//static float fogMinDist;
	//���߼�⣨ʰȡ������
	static float rayTestDis;  //���߼���ܳ���
	static float rayTestStep;  //���߼��ľ���
	static int rayTestStepNum;  //���߼��Ĳ���
	//static glm::vec3 cameraPos;
	static World* world;
};


