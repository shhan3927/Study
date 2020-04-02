#include <iostream>
#include <stack>
#include <vector>
#include <cmath>

using namespace std;

int main()
{
    cin.tie(nullptr);
    ios_base::sync_with_stdio(false);

    vector<vector<int>> numberList;
    bool end = false;
    while(!end)
    {
        int count;
        cin >> count;
        cin.ignore();

        int max = 0;

        if(count == 0)
        {
            end = true;
        }
        else
        {   
            vector<int> buffer;
            for(int i=0; i<count; i++)
            {
                int num;
                cin >> num;
                buffer.push_back(num);
            }

            numberList.push_back(buffer);
        }
    }
    
    return 0;
}
