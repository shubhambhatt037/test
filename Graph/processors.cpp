#include<iostream>
#include<algorithm>
using namespace std;

int numberprocesses(vector<pair<int, int> > &processes)
{
    sort(processes.begin(), processes.end());

    vector<int> processors;

    for(int i=0; i<processes.size(); i++)
    {
        int start = processes[i].first;
        int end = processes[i].second;

        bool assigned = false;

        for(int j=0; j<processors.size(); j++)
        {
            if(processors[j] <= start)
            {
                processors[j] = end;
                assigned = true;
                break;
            }
        }

        if(!assigned)
            processors.push_back(end);
    }
    return processors.size();
}

int main()
{
    int n;
    cout<<"Enter number of processes-> "<<endl;
    cin>>n;
    vector<pair<int, int> > processes;

    for(int i=0; i<n; i++)
    {
        int x,y;
        cin>>x>>y;

        processes.push_back(make_pair(x, y));
    }

    int a = numberprocesses(processes);
    cout<<a<<endl;
    return 0;
}

// #include <iostream>
// #include <vector>
// #include <algorithm>

// using namespace std;

// int getMinProcessors(vector<pair<int, int> >& processes) {
//     int n = processes.size();
    
//     // Sort processes based on their start times
//     sort(processes.begin(), processes.end());
    
//     vector<int> processors; // Tracks the end times of active processors
    
//     for (int i = 0; i < n; i++) {
//         int processStart = processes[i].first;
//         int processEnd = processes[i].second;
        
//         bool assigned = false;
        
//         // Try to assign the current process to an existing processor
//         for (int j = 0; j < processors.size(); j++) {
//             if (processors[j] <= processStart) {
//                 processors[j] = processEnd; // Update the end time of the processor
//                 assigned = true;
//                 break;
//             }
//         }
        
//         // If the process couldn't be assigned to an existing processor, create a new one
//         if (!assigned) {
//             processors.push_back(processEnd);
//         }
//     }
    
//     return processors.size(); // Return the number of processors needed
// }

// int main() {
//     int t; // Number of test cases
//     cin >> t;
    
//     while (t--) {
//         int n; // Number of processes
//         cin >> n;
        
//         vector<pair<int, int> > processes; // Stores the start and end times of processes
        
//         for (int i = 0; i < n; i++) {
//             int start, end;
//             cin >> start >> end;
//             processes.push_back(make_pair(start, end));
//         }
        
//         int minProcessors = getMinProcessors(processes);
//         cout << minProcessors << endl;
//     }
    
//     return 0;
// }
