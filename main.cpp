#include <iostream>
#include <stdio.h>



/* run this program using the console pauser or input loop */

using namespace std;

void mainMenu();
void fixed();
void variable();
void fcfs();
void sjf();
void roundRobin();
void priority();
void multiLevel();
//void bankersAlgorithm();


int main(int argc, char** argv) {
    
    mainMenu();
    
    return 0;
}

    //mainMenu function
    
    void mainMenu(){
    
    int usrChoice;
    
    cout<<"----YOU ARE WELCOME TO MEMORY TECHNIQUE MANAGEMENT SCHEMES----"<<endl;
    cout<<"    ______________________________________________" <<endl;
    
    cout<<"Select 1 for FIXED TECHNIQUE"<<endl;
    cout<<"Select 2 for VARIABLE TECHNIQUE"<<endl;
    cout<<"Select 6 for PRIORITY SCHEDULING ALGORITHM"<<endl;
    cout<<"Select 3 for FSC CPU SCHEDULING ALGORITHM"<<endl;
    cout<<"Select 4 for SJF CPU SCHEDULING ALGORITHM"<<endl;
    cout<<"Select 5 for ROUND ROBIN CPU SCHEDULING ALGORITHM"<<endl;
    cout<<"Select 7 for MULTI-LEVEL SCHEDULING ALGORITHM"<<endl;
    cout<<"Select 8 for BANKERS ALGORITH"<<endl;
    cout<<"9. Quit Program\n"<<endl;
    
    cout<<"Select between 1 & 6. Choose 7 to quit\n"<<endl;
    cin>>usrChoice;
    
    system("CLS");
    
    while(usrChoice <1 || usrChoice> 9){
    
        cout<<"Wrong Input. Please Choose between 1 & 6. Select 7 to quit."<<endl;
        cout<<"Enter again: "<<endl;
        
        cin>>usrChoice;
    }
    
    if(usrChoice == 1){
        fixed();
    }
    else if(usrChoice== 2){
        variable();
    
    }else if(usrChoice == 3){
        fcfs();
    }
    else if(usrChoice == 4){
    
        sjf();
    }
    else if(usrChoice == 5){
    
        roundRobin();
    }
    else if(usrChoice == 6){
    
        priority();
    }
    else if(usrChoice == 7){
        
        multiLevel();
        
    }
    else if(usrChoice == 8){
            //bankersAlgorithm();
    }
}


    //function fixed
    
    void fixed(){

        
    //varibale declarations for various inputs from the user
    
        int memorySize, partition, partitionedSize, externalFrag, InternalFrag, totalInternalFrag = 0;
    int numProcesses[5], i, numProcess, process = 0;
    
    
    //output to screen for user to enter inputs
    
    cout<<"Enter total memory size(in bytes)"<<endl;
    cin>>memorySize;
    
    cout<<"Enter number of partitiions (in bytes)"<<endl;
    cin>>partition;
    
    partitionedSize = memorySize / partition;                    //computation for assigning each partition size
    
    
    cout<<"Each partition size is: " <<partitionedSize<<endl; //displaying each partition size allocated
    
    cout<<"Enter the number of processes: "<<endl;            //propmt for user to enter number of processes
    cin>>numProcess;
    
    externalFrag = memorySize - partition * partitionedSize;            //computation to check for external fragmentation.
    
    for(i = 0; i < numProcess; i++){                        //a for loop to iterate per the number of processes
        
        cout<<"Enter the memory required for process "<<i+1<<":"<<endl;  //loop iterating for user to enter memory for each process
        cin>>numProcesses[i];
    }
    
    cout<<"Number of partitions available in Memory "<<partitionedSize<<endl;        //displaying the total number of each partition
    cout<<"\n\nPROCESS\t MEMORY REQUIRED\t ALLOCATED\t INTERNAL FRAGMENTATION"<<endl;
    
    for (i = 0;i<numProcess && process<partitionedSize;i++){

        
        cout<<"\n\n"<<i+1<<"\t\t"<<numProcesses[i];
        
        if(numProcesses[i] > partition){     //an if statement to check that if any member of the processes is greater than partition size
            cout<<"\t\t NO \t\t\t---";
        }
        else{
            
            cout<<"\t\t YES \t\t\t"<<partition - numProcesses[i];
            
            totalInternalFrag= totalInternalFrag + partition - numProcesses[i];    //determining the total internal fragmentation
                            
            process++;
        }
    }
    if(i < numProcess){                                                    //an if statement to check if any of the processes is greater than memory, then we display memory full.
    
        cout<<"\n\nMemory Full, remaining process cannot be accomodated"<<endl;
    }
    
    cout<<"\n\n Total Internal Fragment is: "<<totalInternalFrag<<endl;        //displaying total internal fragments
    cout<<"\n Total Exernal Fragment is: "<<externalFrag<<endl;                //displaying total external fragments
    
    
    mainMenu();
    
    system("CLS");
}


    void variable(){

    
    int memSize, memRequired[5];    //Declarations of variables.
    int i, tempLoc, n = 0;
    char ch = 'y';
    
    cout<<"Please Enter memory size availabl(in bytes)"<<endl; //display to user to enter memory size available
    cin>>memSize;
    
    tempLoc = memSize;
        
    for(i= 0;ch=='y';i++,n++){      //a for loop to determine if user's response is yes, then more processes should be accomodated
        
        cout<<"Enter the memory required for process"<<i+1<<"(in bytes)"<<endl;   //display for user to enter memory required for processes
        cin>>memRequired[i];
        
        if(memRequired[i] <= tempLoc){     //if memory required to assign process if less than total memory size, assign process to memory
            
            cout<<"\n Memory allocated for process "<<i+1;
            tempLoc = tempLoc - memRequired[i];
        }else{
            cout<<"\n Memory if Full"<<endl;         //else statement to check if memory required for job is larger than memory size, if yes, dont assign.
        }
        cout<<"\nDo you wish to continue (y/n)"<<endl;
        cin>>ch;
    }
    
    cout<<"\n Total Memory available ---"<<memSize<<endl;    //displaying total memory available
    cout<<"\n PROCESS \t\t MEMORY ALLOCATED"<<endl;
    
    for(i=0;i<n;i++){
        
        cout<<"\n"<<i+1<<"\t\t"<<"\t\t"<<memRequired[i];    //displaying outputs of user's inputs
    }
    
    cout<<"\n\n Total Memory Allocated is "<<memSize - tempLoc<<endl;
    cout<<"\n Total external fragment is "<<tempLoc<<endl;
        
       
    }


//function fcfs

void fcfs(){
    
    int burstTime[20], waitTime[20], tat[20];
    int i, numberProcess;
    float wtAvg, tatAvg;
    
    cout<<"---FCFS TECHNIQUE---"<<endl;

    cout<<"\nEnter the number of processes--"<<endl;
    cin>>numberProcess;
    
    
    
    system("CLS");
        
    for(i=0;i<numberProcess;i++){
        cout<<"Enter burst time for process-- "<<i<<endl;
        cin>>burstTime[i];
    }
    waitTime[0] = wtAvg = 0;
    tat[0] = tatAvg = 0;
    
    for(i=1;i<numberProcess;i++){
        
        waitTime[i] = waitTime[i-1] + burstTime[i-1];
        tat[i] = tat[i-1] + burstTime[i];
        wtAvg = wtAvg + waitTime[i];
        tatAvg = tatAvg + tat[i];
    }
    

    cout<<"PROCESS\t"<<"BURST-TIME\t"<<"WAITING-TIME\t"<<"TURNAROUND-TIME\n"<<endl;
    
    for(i=0;i<numberProcess;i++){
    
        cout<<" "<<i<<"\t\t"<<burstTime[i]<<"\t\t\t"<<waitTime[i]<<"\t\t\t"<<tat[i]<<endl;
    }
    
    cout<<"\nAverage Waiting Time-- "<<wtAvg/numberProcess<<endl;
    cout<<"\nAverage Turnaround Time--"<<tatAvg/numberProcess<<endl;
}

 void sjf(){
     
     int p[20],numberProcess,burstTime[20], waitTime[20], tat[20];
     int i, k,  tempLoc;
     float wtAvg, tatAvg;
     
     cout<<"---SJFN TECHNIQUE---"<<endl;
     
     cout<<"\nEnter the number of processes-- "<<endl;
     cin>>numberProcess;
     

     
     for(i=0;i<numberProcess;i++){
         
         p[i]= i;
         
         cout<<"Enter the burst time for process -- "<<i<<endl;
         cin>>burstTime[i];
         
         
     }
     for(i=0;i<numberProcess;i++)
         for(k=i+1;k<numberProcess;k++)
             if(burstTime[i] > burstTime[k]){
                 
                 tempLoc = burstTime[i];
                 burstTime[i] = burstTime[k];
                 burstTime[k] = tempLoc;
                 
                 tempLoc = p[i];
                 p[i] = p[k];
                 p[k] = tempLoc;
             }
         waitTime[0] = wtAvg = 0;
         tat[0] = tatAvg = burstTime[0];
         
         for(i=1;i<numberProcess;i++){
             
             waitTime[i] = waitTime[i-1] + burstTime[i-1];
             tat[i] = tat[i - 1] + burstTime[i];
             wtAvg = wtAvg + waitTime[i];
             tatAvg = tatAvg + tat[i];
         }
         cout<<"\nPROCESS\tBURST-TIME\t\tWAITING-TIME\t\tTURNAROUND-TIME"<<endl;
         
         for(i=0;i<numberProcess;i++)
         
         cout<<"\n"<<p[i]<<"\t"<<burstTime[i]<<"\t\t"<<waitTime[i]<<"\t\t"<<tat[i]<<endl;
         
         cout<<"\nAverage Waiting Time --"<<wtAvg / numberProcess<<endl;
         cout<<"\nAverage Turnaround Time--"<<tatAvg / numberProcess<<endl;
 }
 
 //function roundRobin
 
 void roundRobin(){
     
     int bu[10], wa[10], tat[10], ct[10];
     int i, j, numberProcess, timeSlice;
     float awt=0, att=0, tempLoc=0, max;
     
     cout<<"Enter the Number of processes-- "<<endl;
     cin>>numberProcess;
     
     for(i=0;i<numberProcess;i++){
         
         cout<<"\nEnter burst time for process -- "<<i+1<<endl;
         cin>>bu[i];
         ct[i] = bu[i];
     }
     
     cout<<"\nEnter the size of time slice-- "<<endl;
     cin>>timeSlice;
     max= bu[0];
     
     for(i=1;i<numberProcess;i++)
         if(max < bu[i])
            max = bu[i];
                     
     for(j=0; j<(max/timeSlice)+1;i++)
         for(i=0;i<numberProcess;i++)
             if(bu[i] !=0)
                 if(bu[i] <= timeSlice){
                     
                     tat[i] = tempLoc + bu[i];
                     tempLoc = tempLoc + bu[i];
                     bu[i] = 0;
                 }else{
                     bu[i] = bu[i] - timeSlice;
                     tempLoc = tempLoc + timeSlice;
                 }
    for(i=0;i<numberProcess;i++){
        wa[i] = tat[i] - ct[i];
        att= att + tat[i];
        awt = awt + wa[i];
    }
    cout<<"The Average Turnaround time is --- "<<att/numberProcess<<endl;
    cout<<"The Average waiting time is --- "<<awt/numberProcess<<endl;
    cout<<""<<"PROCESS\t"<<"BURST-TIME\t"<<"WAITING-TIME\t"<<"TURN-AROUND TIME\n"<<endl;
    
    for(i=0;i<numberProcess;i++)
        cout<<""<<i+1<<ct[i]<<wa[i]<<tat[i]<<endl;
    
 }
 
 //function priority
 
 void priority(){
     int p[20], bt[20], pri[20], wt[20], tat[20];
     int i, k, numProcess, temp;
     float wtAvg, tatAvg;
     
     cout<<"---PRIORITY TECHNIQUE---"<<endl;
     
     cout<<"Enter the number of processes-- "<<endl;
     cin>>numProcess;
     
     for(i=0;i<numProcess;i++){
         p[i] = i;
         
         cout<<"Enter the burst time of process-- "<<i<<endl;
         cin>>bt[i];
         
         cout<<"Enter priority of process -- "<<i<<endl;
         cin>>pri[i];
         
     }
     
     for(i=0;i<numProcess;i++)
         for(k=i+1;k<numProcess;k++)
             if(pri[i] > pri[k]){
                 temp = p[i];
                 p[i] = p[k];
                 p[k] = temp;
                 
                 temp = bt[i];
                 bt[i] = bt[k];
                 bt[k] = temp;
                 
                 temp = pri[i];
                 pri[i] = pri[k];
                 pri[k] = temp;
          }
          
          wtAvg = wt[0] = 0;
          tatAvg = tat[0] = bt[0];
          
          for(i=1; i < numProcess; i++){
              wt[i] = wt[i-1] + bt[i-1];
              tat[i] = tat[i-1] + bt[i];
              
              wtAvg = wtAvg + wt[i];
              tatAvg = tatAvg + tat[i];
          }
          
          cout<<"PROCESS \tPRIORITY\tBURST-TIME\tWAITING-TIME\tTURNAROUND-TIME"<<endl;
          
          for(i=0;i<numProcess;i++)
          cout<<p[i]<<"\t\t"<<pri[i]<<"\t\t"<<bt[i]<<"\t\t"<<wt[i]<<"\t\t"<<tat[i]<<endl;
          
          cout<<"\n Average waiting time is-- "<<wtAvg/numProcess<<endl;
          cout<<"\n Average turnaround time is-- "<<tatAvg/numProcess<<endl;
                   
 }
 
 //multi-level
 
 void multiLevel(){
     
     int p[20],bt[20], su[20], wt[20],tat[20],i, k, n, temp;
    float wtavg, tatavg;
    

    
    cout<<"---MULTI-LEVEL TECHNIQUE---\n"<<endl;
    cout<<"Enter the number of processes --- "<<endl;
    cin>>n;
    
    for(i=0;i<n;i++)
    {
        p[i] = i;
        cout<<"Enter the Burst Time of Process  --- "<<i<<endl;
        cin>>bt[i];
        
        cout<<"System/User Process (0/1) ? --- "<<endl;
        cin>>su[i];
    }
    for(i=0;i<n;i++)
        for(k=i+1;k<n;k++)
            if(su[i] > su[k])
            {
                temp=p[i];
                p[i]=p[k];
                p[k]=temp;
                temp=bt[i];
                bt[i]=bt[k];
                bt[k]=temp;
                temp=su[i];
                su[i]=su[k];
                su[k]=temp;
            }
            
            wtavg = wt[0] = 0;
            tatavg = tat[0] = bt[0];
            
    for(i=1;i<n;i++)
    {
        wt[i] = wt[i-1] + bt[i-1];
        tat[i] = tat[i-1] + bt[i];
        
        wtavg = wtavg + wt[i];
        tatavg = tatavg + tat[i];
    }
    
    cout<<"PROCESS\tSYSTEM/USER PROCESS\t BURST-TIME\t WAITING-TIME\tTURNAROUND-TIME"<<endl;;
    
    for(i=0;i<n;i++)

    cout<<p[i]<<"\t\t"<<su[i]<<"\t\t\t"<<bt[i]<<"\t\t"<<wt[i]<<"\t\t"<<tat[i]<<endl;
    
    cout<<"\nAverage Waiting Time is --- "<<wtavg/n<<endl;
    cout<<"\nAverage Turnaround Time is --- "<<tatavg/n<<endl;;
    
    }
    
    





