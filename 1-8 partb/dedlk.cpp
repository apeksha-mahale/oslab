#include <iostream>
#include <string>

using namespace std;

struct process{
        int allocated[3];
        int max[3];
        int need[3];
        string name;
        bool isProcessed;
};

int main()
{
        int n;
        int total[3], available[3];
        string sequence = "";
        cout<<"Enter number of processes: ";
        cin>>n;
        struct process *p = new struct process[n];
        cout<<"Enter total number of resources: ";
        cin>>total[0]>>total[1]>>total[2];
        for(int i=0; i<n; i++){
                cout<<"Enter the process name: ";
                cin>>p[i].name;
                cout<<"Enter the max number of resources of "<<p[i].name<<": ";
                cin>>p[i].max[0]>>p[i].max[1]>>p[i].max[2];
                cout<<"Enter the allocated number of resources of "<<p[i].name<<": ";
                cin>>p[i].allocated[0]>>p[i].allocated[1]>>p[i].allocated[2];
                
                p[i].need[0] = p[i].max[0] - p[i].allocated[0];
                p[i].need[1] = p[i].max[1] - p[i].allocated[1];
                p[i].need[2] = p[i].max[2] - p[i].allocated[2];
                p[i].isProcessed = false;
        }
        
        available[0] = total[0];
        available[1] = total[1];
        available[2] = total[2];

        
        for(int i=0; i<n; i++){
                available[0] -= p[i].allocated[0];
                available[1] -= p[i].allocated[1];
                available[2] -= p[i].allocated[2];
        }
        int i=0;
        bool flag = false;
        while(i<n){
                int select = -1;
                for(int j=0; j<n; j++){
                        if(p[j].need[0] <= available[0] && p[j].need[1] <= available[1] && p[j].need[2] <= available[2] && !p[j].isProcessed){
                                select = j;
                                //cout<<"selected: "<<p[select].name;
                                flag = true;
                                break;
                        }
                }
                if(flag){
                        flag = false;
                        p[select].isProcessed = true;
                        sequence.append(p[select].name);
                        sequence.append(", ");
                        available[0] += p[select].allocated[0]; 
                        available[1] += p[select].allocated[1];
                        available[2] += p[select].allocated[2];
                        //cout<<", available resorces: "<<available[0]<<" "<<available[1]<<" "<<available[2]<<endl;
                        i++;
                }
                else{
                        cout<<"No safe sequence exists"<<endl;
                        return 0;       
                }       
        }
        cout<<"safe sequence is: "<<sequence<<endl;
}

// OUTPUT
/************

Enter number of processes: 5
Enter total number of resources: 10 5 7
Enter the process name: p1
Enter the max number of resources of p1: 7 5 3
Enter the allocated number of resources of p1: 0 1 0
Enter the process name: p2
Enter the max number of resources of p2: 3 2 2
Enter the allocated number of resources of p2: 2 0 0
Enter the process name: p3
Enter the max number of resources of p3: 9 0 2
Enter the allocated number of resources of p3: 3 0 2
Enter the process name: p4
Enter the max number of resources of p4: 2 2 2
Enter the allocated number of resources of p4: 2 1 1
Enter the process name: p5
Enter the max number of resources of p5: 4 3 3
Enter the allocated number of resources of p5: 0 0 2
safe sequence is: p2, p4, p1, p3, p5

************/

Regards,
Eshwar M S