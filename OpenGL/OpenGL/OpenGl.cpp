#include <stdio.h>
#include <iostream>
#include <vector>
#include <sstream>
#include <Windows.h>
#include <GL\glew.h>
#include <GL\freeglut.h>
#include <iostream>

using namespace std;

int n;
int** help;
int* result;
int*** mat;
int R;
int WinW;
int WinH;
const int maxSize = 20;
int amountVerts=0;

struct vertCoord//��������� ��������� ��������� 
{
	int x, y;
};
vertCoord vertC[20];

template<class T>
class Graph
{
	vector<T> vetrexList;
	vector<T> labelList;
	int size;
	bool* visitedVerts = new bool[vetrexList.size()];
public:
	vector<vector<int>> adjMatrix;
	Graph();
	Graph<T>(const int& ksize);
	~Graph();
	void DrawGraph();
	void InsertEdge(const T& vertex1, const T& vertex2, int weight); //������ �����, ����� �������� ��������� �������
	inline void insertVertex(const T& vertex);
	void removeVertex(const T& vertex);
	inline int GetVertPos(const T& vertex);
	inline bool isEmpty();
	inline bool IsFull();
	inline int GetAmountVerts();
	int GetAmountEdges();
	inline int GetWeight(const T& vertex1, const T& vertex2);
	vector<T> GetNbrs(const T& vertex);
	void PrintMatrix();
	void removeEdge(const T& vertex1, const T& vertex2);
	void editEdgeWeight(const T& vertex1, const T& vertex2, int newWeight);
};

Graph<int> graph(20);
template<class T>
vector<T> Graph<T> :: GetNbrs(const T& vetrex) {//������� ��� ��������� ������� �������
		vector<T> nbrsList;
		int pos = this->GetVertPos(vetrex);
		if (pos != -1) {
			for (int i = 0; i < this->vetrexList.size(); i++) {
				if (this->adjMatrix[pos][i] != 0) {
					nbrsList.push_back(this->vetrexList[i]);
				}
			}
		}
		return nbrsList;
	}



template<class T>
inline void Graph<T>:: insertVertex(const T& vert) {//�������, ������� ��������� �������
	if (this->IsFull()) {
		cout << "���������� �������� �������." << endl;
		return;
	}
	this->vetrexList.push_back(vert);
}
template<class T>
void Graph<T>::removeEdge(const T& vertex1, const T& vertex2) {//�������, ������� ������� �����
	int pos1 = GetVertPos(vertex1);
	int pos2 = GetVertPos(vertex2);

	if (pos1 == -1 || pos2 == -1) {
		cout << "����� �� ������ ��� � �����." << endl;
		return;
	}

	if (adjMatrix[pos1][pos2] == 0) {
		cout << "����� ����� ��������� " << vertex1 << " � " << vertex2 << " ���." << endl;
		return;
	}

	adjMatrix[pos1][pos2] = 0;
	adjMatrix[pos2][pos1] = 0;

	cout << "����� ����� ��������� " << vertex1 << " � " << vertex2 << " �������." << endl;
}

template<class T>
void Graph<T>::removeVertex(const T& vertex) {////�������, ������� ������� �������
	int pos = GetVertPos(vertex);
	if (pos == -1) {
		cout << "������� " << vertex << " ��� � �����." << endl;
		return;
	}

	for (int i = 0; i < size; i++) {
		if (adjMatrix[pos][i] != 0) removeEdge(vertex, vetrexList[i]);
		if (adjMatrix[i][pos] != 0) removeEdge(vetrexList[i], vertex);
	}

	vetrexList.erase(vetrexList.begin() + pos);

	// ������� ������� pos �� ������ ������ �������
	for (int i = 0; i < size; i++) {
		adjMatrix[i].erase(adjMatrix[i].begin() + pos);
	}
	// ������� ������ pos �� �������
	adjMatrix.erase(adjMatrix.begin() + pos);

	size--;

	cout << "������� " << vertex << " �������." << endl;
}

template<class T>
int Graph<T>::GetAmountEdges() {//������� ��� ��������� ���������� ����� ��� ������������������ �����
	int amount = 0;
	if (!this->isEmpty()) {
		for (int i = 0; i < this->vetrexList.size(); i++) {
			for (int j = 0; j < this->vetrexList.size(); j++) {
				if (this->adjMatrix[i][j] != 0) {
					amount++;
				}
			}
		}
	}
	return amount / 2;
}

template<class T>
inline int Graph<T>::GetWeight(const T& g1, const T& g2) {//��������� ���� ����� ���������
	if (this->isEmpty()) {
		return 0;
	}
	int g1_p = this->GetVertPos(g1);
	int g2_p = this->GetVertPos(g2);
	if (g1_p == -1 || g2_p == -1) {
		cout << "������ �� ��������� ����� � ����� �� ����������!";
		return 0;
	}
	return this->adjMatrix[g1_p][g2_p];
}

template<class T>
inline int Graph<T>::GetAmountVerts() {//��������� ���������� ������
	return this->vetrexList.size();
}
template<class T>
inline bool Graph<T>::isEmpty() {//�������� ����� �� ��, ��� �� ����
	return this->vetrexList.size() == 0;
}
template<class T>//�������� ����� �� ��, ��� �� ��������
inline bool Graph<T>::IsFull() {
	return (vetrexList.size() == maxSize);
}

template <class T>
inline int Graph<T>::GetVertPos(const T& g) {//��������� ������� ������
	for (int i = 0; i < vetrexList.size(); i++) {
		if (this->vetrexList[i] == g) {
			return i;
		}
	}
	return -1;
}
template<class T>
Graph<T>::Graph() {
	size = maxSize;
	labelList.resize(size, 1000000);
	adjMatrix.resize(size, vector<int>(size, 0));
	visitedVerts = new bool[size];
}

template<class T>
Graph<T>::Graph(const int& ksize) {
	size = ksize;
	labelList.resize(size, 1000000);
	adjMatrix.resize(size, vector<int>(size, 0));
	visitedVerts = new bool[size];
}

template<class T>
Graph<T>::~Graph() {//���������� �����

}

template<class T>
void Graph<T>::InsertEdge(const T& vetrex1, const T& vetrex2, int weight) {//������� ����� ��� ������������������ �����
	if (GetVertPos(vetrex1) != (-1) && this->GetVertPos(vetrex2) != (-1)) {
		int vertPos1 = GetVertPos(vetrex1);
		int vertPos2 = GetVertPos(vetrex2);
		if (this->adjMatrix[vertPos1][vertPos2] != 0 && this->adjMatrix[vertPos2][vertPos1] != 0) {
			cout << "����� ����� ��������� ��� ����" << endl;
			return;
		}
		else {
			this->adjMatrix[vertPos1][vertPos2] = weight;
			this->adjMatrix[vertPos2][vertPos1] = weight;
		}
	}
	else {
		cout << "�����-���� ������� ��� � �����" << endl;
		return;
	}
}

template<class T>
void Graph<T>::PrintMatrix() {//������ ������� ��������� �����
	if (!this->isEmpty()) {
		cout << "������� ���������: " << endl;
		cout << "- ";
		for (int i = 0; i < vetrexList.size(); i++) {
			cout << " " << vetrexList[i] << " ";
		}
		cout << endl;
		for (int i = 0; i < this->vetrexList.size(); i++) {
			cout << this->vetrexList[i] << " ";
			for (int j = 0; j < this->vetrexList.size(); j++) {
				cout << " " << this->adjMatrix[i][j] << " ";
			}
			cout << endl;
		}
	}
	else {
		cout << "���� ����" << endl;
	}
}
template<class T>
void Graph<T>::editEdgeWeight(const T& vertex1, const T& vertex2, int newWeight) {//�������, ������� ������ ��� ����� ����� ���������
	int pos1 = GetVertPos(vertex1);
	int pos2 = GetVertPos(vertex2);

	if (pos1 == -1 || pos2 == -1) {
		cout << "����� �� ������ ��� � �����." << endl;
		return;
	}

	if (adjMatrix[pos1][pos2] == 0) {
		cout << "����� ����� ��������� " << vertex1 << " � " << vertex2 << " ���." << endl;
		return;
	}

	adjMatrix[pos1][pos2] = newWeight;
	adjMatrix[pos2][pos1] = newWeight;

	cout << "��� ����� ����� ��������� " << vertex1 << " � " << vertex2 << " ������� �� " << newWeight << "." << endl;
}

void answer(int*** mat, int n, int** help, int* path)//��� ������� ��������� �������� ������� ������ ������������, ��������� ���������� ��������.
{
	for (int l = 0; l < n; l++)
	{
		for (int i = 0; i < n; i++)
		{
			int min = 1000000;
			for (int j = 0; j < n; j++)
			{
				if (mat[i][j] && min > *mat[i][j])
				{
					min = *mat[i][j];
				}
			}
			for (int j = 0; j < n; j++)
			{
				if (mat[i][j])
				{
					*mat[i][j] -= min;
				}
			}
		}
		for (int j = 0; j < n; j++)
		{
			int min = 1000000;
			for (int i = 0; i < n; i++)
			{
				if (mat[i][j] && min > *mat[i][j])
				{
					min = *mat[i][j];
				}
			}
			for (int i = 0; i < n; i++)
			{
				if (mat[i][j])
				{
					*mat[i][j] -= min;
				}
			}
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				help[i][j] = 0;
			}
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (mat[i][j] && !*mat[i][j])
				{
					int hmin = 1000000;
					int vmin = 1000000;

					for (int l = 0; l < n; l++)
					{
						if (l != i && mat[l][j] && hmin > *mat[l][j])
						{
							hmin = *mat[l][j];
						}
					}
					for (int l = 0; l < n; l++)
					{
						if (l != j && mat[i][l] && hmin > *mat[i][l])
						{
							vmin = *mat[i][l];
						}
					}
					help[i][j] = hmin + vmin;
				}
			}
		}
		int mcost = 0, mi = 0, mj = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (mat[i][j] && mcost < help[i][j])
				{
					mcost = help[i][j];
					mi = i;
					mj = j;
				}
			}
		}
		path[mi] = mj;

		for (int i = 0; i < n; i++)
		{
			mat[i][mj] = nullptr;
		}
		for (int i = 0; i < n; i++)
		{
			mat[mi][i] = nullptr;
		}

		mat[mj][mi] = nullptr;
	}
}

void preparation(int***& mat, int& n, int**& help, int*& result)// ��� ������� �������������� ������ ��� ��������� TSP (������������)
{
	n = amountVerts;// ����������� ���������� ������ �� �����
	// �������� ������ ��� ��������������� ������� help � result
	help = new int* [n];
	result = new int[n];
	// �������� ������ ��� ���������� ������� mat, ������� ����� ������� ������� ��������� �����
	mat = new int** [n];
	// �������������� help
	for (int i = 0; i <= n; i++)
	{
		help[i] = new int[n];
	}
	// ��������� mat ���������� �� ������� ��������� �����
	for (int i = 0; i <= n; i++)
	{
		mat[i] = new int* [n];
		for (int j = 0; j < n; j++)
		{
			if (graph.adjMatrix[i][j] == 0)
			{
				mat[i][j] = nullptr;
				continue;
			}
			mat[i][j] = new int(graph.adjMatrix[i][j]);
		}
	}
}

void TSP(int*** mat, int n, int** help, int* result)// ��� ������� �������� ������ ����� ��� ������� ������ ������������ (TSP). 
{
	preparation(mat, n, help, result);
	int s = 0;
	answer(mat, n, help, result);
	cout << endl << "������� �����: ";
	for (int i = 0, j = 0; i < n; i++)
	{
		j = result[i];
		cout << i + 1 << " -> " << j + 1 << '\t';
		s += graph.adjMatrix[i][j];
	}
	cout << endl;
	cout << endl << "���������� ����: ";
	int tmp = 0;
	for (int l = 0; l < n;)
	{
		for (int i = 0, j = 0; i < n; i++)
		{
			if (tmp == 0 || i + 1 == tmp)
			{
				if (tmp == 0)
				{
					cout << i + 1;
				}
				j = result[i];
				tmp = j + 1;
				if (tmp > 0)
				{
					cout << " -> " << tmp;
				}
				l++;
			}
		}
	}
	cout << endl << "����������� ����������: " << s;
	cout << endl;
}



void setCoord(int i, int n)
{
	int R_;

	int x0 = WinW / 2;
	int y0 = WinH / 2;
	if (WinW > WinH)
	{
		R = 5 * (WinH / 13) / n;
		R_ = WinH / 2 - R - 10;
	}
	else {
		R = 5 * (WinW / 13) / n;
		R_ = WinW / 2 - R - 10;
	}
	float theta = 2.0f * 3.1415926f * float(i) / float(n);
	float y1 = R_ * cos(theta) + y0;
	float x1 = R_ * sin(theta) + x0;

	vertC[i].x = x1;
	vertC[i].y = y1;
}

void drawCircle(int x, int y, int R)//�������, ��������������� ��� ��������� ����� 
{
	glColor3f(1.0,0.0,0.0);
	float x1, y1;
	glBegin(GL_POLYGON);
	for (int i = 0; i < 360; i++)
	{
		float theta = 2.0f * 3.1415926f * float(i) / float(360);
		y1 = R * cos(theta) + y;
		x1 = R * sin(theta) + x;;
		glVertex2f(x1, y1);
	}
	glEnd();

	glColor3f(0.0f, 0.0f, 0.0f);
	float x2, y2;
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < 360; i++)
	{
		float theta = 2.0f * 3.1415926f * float(i) / float(360);
		y2 = R * cos(theta) + y;
		x2 = R * sin(theta) + x;
		glVertex2f(x2, y2);
	}
	glEnd();
}

void drawText(int nom, int x1, int y1)//��������� ������ � �������
{
	GLvoid* font = GLUT_BITMAP_TIMES_ROMAN_24;
	string s = to_string(nom);
	glRasterPos2i(x1 - 5, y1 - 5);
	for (int j = 0; j < s.length(); j++)
		glutBitmapCharacter(font, s[j]);
}

void drawVertex(int n)//��������� �������, ������ � ���
{
	for (int i = 0; i < n; i++) {
		drawCircle(vertC[i].x, vertC[i].y, R);
		drawText(i + 1, vertC[i].x, vertC[i].y);
	}
}

void drawLine(int text, int x0, int y0, int x1, int y1) {//��������� �����, � ������ �� ����� 
	glColor3f(0.0, 0.0, 0.0);  
	glBegin(GL_LINES);
	glVertex2i(x0, y0);
	glVertex2i(x1, y1);
	glEnd();

	glColor4f(1.0f, 1.0f, 1.0f, 0.0f);
	drawText(text, (x0 + x1) / 2 + 11, (y0 + y1) / 2 + 11);
}



template<class T>
void Graph<T>::DrawGraph()//������� �������, ������� ������ ��� ����
{
	int n = vetrexList.size();
	for (int i = 0; i < n; i++)
	{
		setCoord(i, n);
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			int a = adjMatrix[i][j];
			if (a != 0)
			{
				drawLine(a, vertC[i].x, vertC[i].y, vertC[j].x, vertC[j].y);
			}
		}
	}
	drawVertex(n);
}

void reshape(int w, int h)//������� ���������� �� ��������� ������� ������
{
	WinW = w;
	WinH = h;
	glViewport(0, 0, (GLsizei)WinW, (GLsizei)WinH);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, (GLdouble)WinW, 0, (GLdouble)WinH);
	glutPostRedisplay();
}

void drawMenuText(string text, int x1, int y1)//������� ��� ������ � ��� ������ � �������
{
	GLvoid* font = GLUT_BITMAP_9_BY_15;
	string s = text;
	glRasterPos2i(x1 + 5, y1 - 20);
	for (int j = 0; j < s.length(); j++)
		glutBitmapCharacter(font, s[j]);
}

void drawMenu()//�������� ���� � ��������������� ���������
{
	int shift = 60;
	int height = 730;

	glColor3d(0.0, 0.0, 0.0);
	glBegin(GL_QUADS);
	glVertex2i(shift, height - shift - 30);
	glVertex2i(shift + 135, height - shift - 30);
	glVertex2i(shift + 135, height - shift);
	glVertex2i(shift, height - shift);
	glEnd();
	glColor3d(1, 1, 1);
	drawMenuText("insertVertex", shift, height - shift - 2);

	glColor3d(0.0, 0.0, 0.0);
	glBegin(GL_QUADS);
	glVertex2i(shift, height - shift - 70);
	glVertex2i(shift + 135, height - shift - 70);
	glVertex2i(shift + 135, height - shift - 40);
	glVertex2i(shift, height - shift - 40);
	glEnd();
	glColor3d(1, 1, 1);
	drawMenuText("DeleteVertex", shift, height - shift - 42);

	glColor3d(0.0, 0.0, 0.0);
	glBegin(GL_QUADS);
	glVertex2i(shift, height - shift - 110);
	glVertex2i(shift + 135, height - shift - 110);
	glVertex2i(shift + 135, height - shift - 80);
	glVertex2i(shift, height - shift - 80);
	glEnd();
	glColor3d(1, 1, 1);
	drawMenuText("PrintMatrix", shift, height - shift - 82);

	glColor3d(0.0, 0.0, 0.0);
	glBegin(GL_QUADS);
	glVertex2i(shift, height - shift - 150);
	glVertex2i(shift + 135, height - shift - 150);
	glVertex2i(shift + 135, height - shift - 120);
	glVertex2i(shift, height - shift - 120);
	glEnd();
	glColor3d(1, 1, 1);
	drawMenuText("TSP", shift, height - shift - 122);

	glColor3d(0.0, 0.0, 0.0);
	glBegin(GL_QUADS);
	glVertex2i(shift, height - shift - 190);
	glVertex2i(shift + 135, height - shift - 190);
	glVertex2i(shift + 135, height - shift - 160);
	glVertex2i(shift, height - shift - 160);
	glEnd();
	glColor3d(1, 1, 1);
	drawMenuText("editEdgeWeight", shift, height - shift - 162);
}

void mouseClick(int btn, int stat, int x, int y) {//�������, ������� ��������� ����������������� � ����� ����� ������������, ��������, ������� � �.�.
	int shift = 60;
	int height = 730;

	if (stat == GLUT_DOWN) {

		if (x > shift && x < shift + 135 && y >  shift && y < shift + 30)
		{
			int vertex;
			int sourceVertex;
			int targetVetrex;
			int edgeWeight;
			int Weight;
			int g, k;
			cout << "������� ���-�� ������, ������� �� ������ ��������: ";
			cin >> g;
			cout << "������� ���-�� ����, ������� ������ ��������: ";
			cin >> k;
			for (int i = 0; i < g; i++) {
				cout << "�������: ";
				cin >> vertex;
				graph.insertVertex(vertex);
				amountVerts++;
				cout << endl;
			}
			for (int i = 0; i < k; i++) {
				cout << "�������� �������: ";
				cin >> sourceVertex;
				cout << endl;
				cout << "�������� �������: ";
				cin >> targetVetrex;
				cout << endl;
				cout << "��� �����: ";
				cin >> Weight;
				cout << endl;
				int* targetVerPtr = &targetVetrex;
				graph.InsertEdge(sourceVertex, targetVetrex, Weight);
			}

			
		}
		if (x > shift && x < shift + 135 && y > shift + 40 && y < shift + 70)
		{
			int sourceVertex;
			int targetVertex;
			int edgeWeight;

			cout << "������� ������� >> "; cin >> sourceVertex; cout << endl;

				graph.removeVertex(sourceVertex);
				amountVerts--;
		
	
		}
		if (x > shift && x < shift + 135 && y >  shift + 80 && y < shift + 100)
		{
			graph.PrintMatrix();
		}
		if (x > shift && x < shift + 135 && y >  shift + 120 && y < shift + 140)
		{
			TSP(mat, n, help, result);
		}
		if (x > shift && x < shift + 135 && y >  shift + 160 && y < shift + 180)
		{
			int vertex,  Weight, vertex1;
			cout << "������� ������ ������, ����� �������� ����� �������� ��� �����: ";
			cin >> vertex;
			cin >> vertex1;
			cout << endl << endl;
			cout << "������� ������ ���: ";
			cin >> Weight;
			graph.editEdgeWeight(vertex, vertex1, Weight);
		}
	}
	glutPostRedisplay();
}

void display()//������ ������ ������ � ������ ������� ��������� ����� 
{
	glShadeModel(GL_SMOOTH);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, WinW, 0, WinH); 
	glViewport(0, 0, WinW, WinH);
	glClearColor(0.0, 0.0, 1.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	graph.DrawGraph();
	drawMenu();
	glutSwapBuffers();
}

int main(int argc, char* argv[])
{
	setlocale(LC_ALL, "rus");
	system("chcp 1251>NULL");
	glutInit(&argc, argv);
	int Verts, Edges, vertex, sourceVertex, targetVetrex, Weight;
	cout << "������� ���������� ������: " << endl;
	cin >> Verts;
	cout << "������� ���������� ����� �����: " << endl;
	cin >> Edges;
	cout << endl;
	for (int i = 0; i < Verts; i++) {
		cout << "�������: ";
		cin >> vertex;
		graph.insertVertex(vertex);
		amountVerts++;
		cout << endl;
	}
	for (int i = 0; i < Edges; i++) {
		cout << "�������� �������: ";
		cin >> sourceVertex;
		cout << endl;
		cout << "�������� �������: ";
		cin >> targetVetrex;
		cout << endl;
		cout << "��� �����: ";
		cin >> Weight;
		cout << endl;
		int* targetVerPtr = &targetVetrex;
		graph.InsertEdge(sourceVertex, targetVetrex, Weight);
	}
	cout << endl;
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowSize(1350, 730);
	glutCreateWindow("Graph");
	WinW = glutGet(GLUT_WINDOW_WIDTH);
	WinH = glutGet(GLUT_WINDOW_HEIGHT);
	glLineWidth(2);
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMouseFunc(mouseClick);
	glutMainLoop();
	return 0;
}