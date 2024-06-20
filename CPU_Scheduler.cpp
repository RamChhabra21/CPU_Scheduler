#include <bits/stdc++.h>
using namespace std;

bool cmp_SJF(pair<int, vector<int>> p1, pair<int, vector<int>> p2){
    if(p1.second[2] != p2.second[2]){
        return p1.second[2] < p2.second[2];
    }
    return p1.second[3] > p2.second[3];
}
 
void SJF(int total_BT, vector<pair<int, vector<int>>> processes, vector<pair<int, vector<int>>> &original){
    int time_quantum = 0;
    int curr_time = 0; 
    while(total_BT > 0){
        sort(processes.begin(), processes.end(), cmp_SJF);
        int process_to_be_executed = -1;
        for (int i = 0; i < processes.size(); ++i){
            if(processes[i].second[1] <= curr_time){
                process_to_be_executed = i;
                int j;
                for(j = 0; j < original.size(); j++){
                    if (original[j].second[0] == processes[i].second[0]){
                        break;
                    }
                }
                original[j].second.push_back(curr_time - original[j].second[1]);
                original[j].second.push_back(curr_time + original[j].second[2]);
                original[j].second.push_back(original[j].second[6] - original[j].second[1] - original[j].second[2]);
                original[j].second.push_back(original[j].second[6] - original[j].second[1]);
                break;
            }
        }
        if (process_to_be_executed == -1){
            cout << "NOP" << " ";
            curr_time++;
            continue;
        }
        time_quantum = processes[process_to_be_executed].second[2];
        curr_time += time_quantum;
        for (int i = 0; i < time_quantum; ++i){
            cout << "P" << processes[process_to_be_executed].second[0] << " ";
        }
        total_BT -= time_quantum;
        processes[process_to_be_executed].second[4] += time_quantum;
        processes.erase(processes.begin()+process_to_be_executed);
    }
} 

bool cmp_LJF(pair<int, vector<int>> p1, pair<int, vector<int>> p2){
    if(p1.second[2] != p2.second[2]){
        return p1.second[2] > p2.second[2];
    }
    return p1.second[3] > p2.second[3];
}
 
void LJF(int total_BT, vector<pair<int, vector<int>>> processes, vector<pair<int, vector<int>>> &original){
    int time_quantum = 0;
    int curr_time = 0;    
    while(total_BT > 0){
        sort(processes.begin(), processes.end(), cmp_LJF);
        int process_to_be_executed = -1;
        for (int i = 0; i < processes.size(); ++i){
            if(processes[i].second[1] <= curr_time){
                process_to_be_executed = i;
                int j;
                for(j = 0; j < original.size(); j++){
                    if (original[j].second[0] == processes[i].second[0]){
                        break;
                    }
                }
                original[j].second.push_back(curr_time - original[j].second[1]);
                original[j].second.push_back(curr_time + original[j].second[2]);
                original[j].second.push_back(original[j].second[6] - original[j].second[1] - original[j].second[2]);
                original[j].second.push_back(original[j].second[6] - original[j].second[1]);
                break;
            }
        }
        if (process_to_be_executed == -1){
            cout << "NOP" << " ";
            curr_time++;
            continue;
        }
        time_quantum = processes[process_to_be_executed].second[2];
        curr_time += time_quantum;
        for (int i = 0; i < time_quantum; ++i){
            cout << "P" << processes[process_to_be_executed].second[0] << " ";
        }
        total_BT -= time_quantum;
        processes[process_to_be_executed].second[4] += time_quantum;
        processes.erase(processes.begin()+process_to_be_executed);
    }
} 

bool cmp_SRJF(pair<int, vector<int>> p1, pair<int, vector<int>> p2){
    if(p1.second[2] != p2.second[2]){
        return p1.second[2] < p2.second[2];
    }
    return p1.second[3] > p2.second[3];
}
 
void SRJF(int total_BT, vector<pair<int, vector<int>>> processes, vector<pair<int, vector<int>>> &original){
    int curr_time = 0;
    int time_quantum = 0;
    int j;
    unordered_map<int, int> umap;
    while(total_BT > 0){
        sort(processes.begin(), processes.end(), cmp_SRJF);
        int process_to_be_executed = -1;
        for (int i = 0; i < processes.size(); ++i){
            if(processes[i].second[1] <= curr_time){
                process_to_be_executed = i;
                for(j = 0; j < original.size(); j++){
                    if (original[j].second[0] == processes[i].second[0]){
                        if(umap.find(j) == umap.end()){
                            umap[j] = 1;
                            original[j].second.push_back(curr_time - original[j].second[1]);
                        }
                        break;
                    }
                }
                break;
            }
        }
        if (process_to_be_executed == -1){
            cout << "NOP" << " ";
            curr_time++;
            continue;
        }
        time_quantum = 1;
        curr_time += time_quantum;
        for (int i = 0; i < time_quantum; ++i){
            cout << "P" << processes[process_to_be_executed].second[0] << " ";
        }
        total_BT -= time_quantum;
        processes[process_to_be_executed].second[4] += time_quantum;
        if (time_quantum == processes[process_to_be_executed].second[2]){
            processes.erase(processes.begin()+process_to_be_executed);
            original[j].second.push_back(curr_time);
            original[j].second.push_back(curr_time-original[j].second[1]-original[j].second[2]);
            original[j].second.push_back(curr_time-original[j].second[1]);
        }else{
            processes[process_to_be_executed].second[2]-= time_quantum;
        }
    }
} 

bool cmp_LRJF(pair<int, vector<int>> p1, pair<int, vector<int>> p2){
    if(p1.second[2] != p2.second[2]){
        return p1.second[2] > p2.second[2];
    }
    return p1.second[3] > p2.second[3];
}
 
void LRJF(int total_BT, vector<pair<int, vector<int>>> processes, vector<pair<int, vector<int>>> &original){
    int time_quantum = 0;
    int curr_time = 0;   
    int j;
    unordered_map<int, int> umap;
    while(total_BT > 0){
        sort(processes.begin(), processes.end(), cmp_LRJF);
        int process_to_be_executed = -1;
        for (int i = 0; i < processes.size(); ++i){
            if(processes[i].second[1] <= curr_time){
                process_to_be_executed = i;
                for(j = 0; j < original.size(); j++){
                    if (original[j].second[0] == processes[i].second[0]){
                        if(umap.find(j) == umap.end()){
                            umap[j] = 1;
                            original[j].second.push_back(curr_time - original[j].second[1]);
                        }
                        break;
                    }
                }
                break;
            }
        }
        if (process_to_be_executed == -1){
            cout << "NOP" << " ";
            curr_time++;
            continue;
        }
        time_quantum = 1;
        curr_time += time_quantum;
        for (int i = 0; i < time_quantum; ++i){
            cout << "P" << processes[process_to_be_executed].second[0] << " ";
        }
        total_BT -= time_quantum;
        processes[process_to_be_executed].second[4] += time_quantum;
        if (time_quantum == processes[process_to_be_executed].second[2]){
            processes.erase(processes.begin()+process_to_be_executed);
            original[j].second.push_back(curr_time);
            original[j].second.push_back(curr_time-original[j].second[1]-original[j].second[2]);
            original[j].second.push_back(curr_time-original[j].second[1]);
        }else{
            processes[process_to_be_executed].second[2]-= time_quantum;
        }
    }
} 

bool cmp_FCFS(pair<int, vector<int>> p1, pair<int, vector<int>> p2){
    if(p1.second[1] != p2.second[1]){
        return p1.second[1] < p2.second[1];
    }
    return p1.second[3] > p2.second[3];
}
 
void FCFS(int total_BT, vector<pair<int, vector<int>>> processes, vector<pair<int, vector<int>>> &original){
    int time_quantum = 0;
    int curr_time = 0;    
    while(total_BT > 0){
        sort(processes.begin(), processes.end(), cmp_FCFS);
        int process_to_be_executed = -1;
        for (int i = 0; i < processes.size(); ++i){
            if(processes[i].second[1] <= curr_time){
                process_to_be_executed = i;
                int j;
                for(j = 0; j < original.size(); j++){
                    if (original[j].second[0] == processes[i].second[0]){
                        break;
                    }
                }
                original[j].second.push_back(curr_time - original[j].second[1]);
                original[j].second.push_back(curr_time + original[j].second[2]);
                original[j].second.push_back(original[j].second[6] - original[j].second[1] - original[j].second[2]);
                original[j].second.push_back(original[j].second[6] - original[j].second[1]);
                break;
            }
        }
        if (process_to_be_executed == -1){
            cout << "NOP" << " ";
            curr_time++;
            continue;
        }
        time_quantum = processes[process_to_be_executed].second[2];
        curr_time += time_quantum;
        for (int i = 0; i < time_quantum; ++i){
            cout << "P" << processes[process_to_be_executed].second[0] << " ";
        }
        total_BT -= time_quantum;
        processes[process_to_be_executed].second[4] += time_quantum;
        processes.erase(processes.begin()+process_to_be_executed);
    }
} 

int main(){
    int number_of_processes, process_number, arrival_time, burst_time, completion_time, turnaround_time, waiting_time, arrival_time_check, time_quantum = 0, total_BT = 0;
    vector<pair<int, vector<int>>> processes;
    cin >> number_of_processes;
    for(int i = 0; i < number_of_processes; ++i){
        cin >> process_number >> arrival_time >> burst_time;
        vector<int> v;
        v.push_back(process_number);
        v.push_back(arrival_time);
        v.push_back(burst_time);
        v.push_back(arrival_time+burst_time);
        v.push_back(0);
        total_BT += burst_time;
        processes.push_back({i, v});
    }
    vector<pair<int, vector<int>>> original = processes;
    FCFS(total_BT, processes, original);
    for(int i = 0; i < number_of_processes; i++){
        int j;
        for(j = 0; j < original.size(); j++){
            if(original[j].second[0] == i+1){
                break;
            }
        }
        original[j].second.push_back(original[j].second[2]-original[j].second[1]);
    }
    LJF(total_BT, processes, original);
    for(int i = 0; i < number_of_processes; i++){
        int j;
        for(j = 0; j < original.size(); j++){
            if(original[j].second[0] == i+1){
                break;
            }
        }
        original[j].second.push_back(original[j].second[2]-original[j].second[1]);
    }
    SJF(total_BT, processes, original);
    for(int i = 0; i < number_of_processes; i++){
        int j;
        for(j = 0; j < original.size(); j++){
            if(original[j].second[0] == i+1){
                break;
            }
        }
        original[j].second.push_back(original[j].second[2]-original[j].second[1]);
    }
    LRJF(total_BT, processes, original);
    for(int i = 0; i < number_of_processes; i++){
        int j;
        for(j = 0; j < original.size(); j++){
            if(original[j].second[0] == i+1){
                break;
            }
        }
        original[j].second.push_back(original[j].second[2]-original[j].second[1]);
    }
    SRJF(total_BT, processes, original);
    for(int i = 0; i < number_of_processes; i++){
        int j;
        for(j = 0; j < original.size(); j++){
            if(original[j].second[0] == i+1){
                break;
            }
        }
        original[j].second.push_back(original[j].second[2]-original[j].second[1]);
    }
    cout << endl;
    cout << "N" << " ";
    for(int i = 1; i < total_BT; ++i){
        cout << i << " ";
    }
    cout << total_BT << endl;
    cout << "N" << " ";
    for(int i = 0; i < number_of_processes; i++){
        int j;
        for(j = 0; j < original.size(); j++){
            if(original[j].second[0] == i+1){
                break;
            }
        }
        cout << original[j].second[1] << " ";
    }
    cout << endl;
    cout << "N" << " ";
    for(int i = 0; i < number_of_processes; i++){
        int j;
        for(j = 0; j < original.size(); j++){
            if(original[j].second[0] == i+1){
                break;
            }
        }
        cout << original[j].second[2] << " ";
    }
    cout << endl;
    for(int i = 0; i < number_of_processes; i++){
        int j;
        for(j = 0; j < original.size(); j++){
            if(original[j].second[0] == i+1){
                break;
            }
        }
        cout << "P" << original[j].second[0] << " ";
    }
    cout << "NOP" << endl;
    return 0;
}
