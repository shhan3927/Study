#pragma ones

#include <functional>
#include <vector>

using namespace std;

class SegmentTree
{
public:
    virtual ~SegmentTree()
    {
        if(container != nullptr)
        {
            delete[] container;
            container = nullptr;
        }
    }

public:
    void Init(int* arr, int size);
    void Update(int index, int value);
    int GetSum(int left, int right);
    void Foreach(function<void (int)> func);

private:
    int Init(int index, int start, int end);
    void Update(int node, int start, int end, int index, int diff);
    int GetSum(int node, int left, int right, int start, int end);

private:
    vector<int> v;
    int capacity = 0;
    int* container = nullptr;
};
