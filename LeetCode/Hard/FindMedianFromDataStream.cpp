// https://leetcode.com/problems/find-median-from-data-stream/

#include <bits/stdc++.h>
using namespace std;

class MedianFinder
{
public:
    priority_queue<int, vector<int>> pqmax;
    priority_queue<int, vector<int>, greater<int>> pqmin;
    MedianFinder()
    {
    }

    void addNum(int x)
    {
        if (pqmin.size() == pqmax.size())
        {
            if (pqmax.size() == 0)
            {
                pqmax.push(x);
                return;
            }

            if (x < pqmax.top())
            {
                pqmax.push(x);
            }
            else
            {
                pqmin.push(x);
            }
        }
        else
        {
            if (pqmax.size() > pqmin.size())
            {
                if (x >= pqmax.top())
                {
                    pqmin.push(x);
                }
                else
                {
                    int temp = pqmax.top();
                    pqmax.pop();
                    pqmin.push(temp);
                    pqmax.push(x);
                }
            }
            else
            {
                if (x <= pqmin.top())
                {
                    pqmax.push(x);
                }
                else
                {
                    int temp = pqmin.top();
                    pqmin.pop();
                    pqmax.push(temp);
                    pqmin.push(x);
                }
            }
        }
    }

    double findMedian()
    {
        if (pqmin.size() == pqmax.size())
        {
            return (pqmin.top() + pqmax.top()) / 2.0;
        }
        else if (pqmax.size() >= pqmin.size())
        {
            return pqmax.top();
        }
        else
        {
            return pqmin.top();
        }
    }
};

int main()
{

    MedianFinder *obj = new MedianFinder();

    obj->addNum(1);
    obj->addNum(2);

    double param_1 = obj->findMedian();

    obj->addNum(3);

    double param_2 = obj->findMedian();

    cout << param_1 << " " << param_2 << endl;

    return 0;
}

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */