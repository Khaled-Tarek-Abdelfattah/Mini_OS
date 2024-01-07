#include<iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

void FCFS(int n) {
    vector <pair<int, string>> sp;
    vector <pair<int, int>> se;
    for (int i = 0; i < n; i++) {
        string process;
        int start_time, duration, end_time;
        cout << "Enter Process name: ";
        cin >> process;
        cout << "Enter Process start time: ";
        cin >> start_time;
        cout << "Enter Process Duration: ";
        cin >> duration;
        end_time = duration;
        sp.push_back({ start_time, process });

        se.push_back({ start_time,end_time });
    }

    sort(sp.begin(), sp.end());
    sort(se.begin(), se.end());
    for (int i = 0; i < n; i++) {
        if (i == n - 1) {
            cout << sp[i].second << endl;

        }
        else {
            cout << sp[i].second << "--->";
        }
    }

    int current_time = se[0].first;
    for (int i = 0; i < n; i++) {
        if (i == n - 1) {
            cout << "(" << current_time << "->" << current_time + se[i].second << ")" << endl;

        }
        else {
            cout << "(" << current_time << "->" << current_time + se[i].second << ")" << "--->";

        }
        current_time += se[i].second;
    }
}
void PRIORTY(int n) {
    vector <pair<int, string>> sp;
    vector <pair<int, int>> sd;
    vector <pair<int, int>> spr;
    for (int i = 0; i < n; i++) {
        string process;
        int start_time, duration, priorty;
        cout << "Enter Process name: ";
        cin >> process;
        cout << "Enter Process start time: ";
        cin >> start_time;
        cout << "Enter Process Duration: ";
        cin >> duration;
        cout << "Enter Process priority: ";
        cin >> priorty;

        sp.push_back({ start_time, process });

        sd.push_back({ start_time,duration });

        spr.push_back({ start_time,priorty });
    }

    sort(sp.begin(), sp.end());
    sort(sd.begin(), sd.end());
    sort(spr.begin(), spr.end());

    queue <string> q;
    vector <pair<int, int>> tempvec = spr;
    vector <pair<int, string>> temppr = sp;
    int current_time = sp[0].first;



    for (int i = 0; i < n; i++)
    {
        string current_process;
        int temp = 0;
        int maxpr = 0;
        int m = 0;
        if (tempvec.empty()) {
            break;
        }
        for (int j = 0; j < n - i; j++)
        {
            if (tempvec[j].second > maxpr && tempvec[j].first <= current_time) {
                current_process = temppr[j].second;
                maxpr = tempvec[j].second;
                m = j;
            }
        }
        q.push(temppr[m].second);
        tempvec.erase(tempvec.begin() + m);
        temppr.erase(temppr.begin() + m);
        current_time += sd[m].second;
    }

    for (int i = 0; i < n; i++)
    {
        if (q.empty())
        {
            break;
        }
        if (i == n - 1) {
            cout << q.front() << endl;
        }
        else {
            cout << q.front() << "-->";
        }
        q.pop();
    }
}
int main()

{
    int n;

    cout << "Enter The Number of Processes: ";
    cin >> n;

    FCFS(n); /*To Schedule processes by Firt Come First Served Algorithm*/

    PRIORTY(n); /*To Schedule processes by Priority Algorithm*/
    

   
    return 0;

}