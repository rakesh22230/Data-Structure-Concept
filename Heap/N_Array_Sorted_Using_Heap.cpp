#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> PAIR;
int main(){

    int n;
    cin>>n;
    vector<vector<int> > allvalues(n);
    // take input for 2D values 
    for(int i=0;i<n;i++){
        int size;
        cin>>size;
        allvalues[i] = vector<int> (size);
        for(int k=0;k<size;k++){
            cin>>allvalues[i][k];
        }
    }

     vector<int>indexTracker(n,0);
     priority_queue<PAIR,vector<PAIR>,greater<PAIR> > PQ;

       // -------- Initialization Part --------


     for(int i=0;i<n;i++){
        PQ.push(make_pair(allvalues[i][0],i) );
     }

     vector<int>ans;
   
    // -------- Merge K sorted arrays using Min-Heap (Priority Queue) --------

     while(!PQ.empty()) {
         PAIR x = PQ.top();
         PQ.pop();
          
         ans.push_back(x.first);

         
        // If there are more elements left in the same array

         if( indexTracker[x.second]+1 < allvalues[x.second].size()  ){
           // Push the next element from the same array into the heap
            PQ.push(make_pair(allvalues[x.second][indexTracker[x.second] + 1], x.second));

         }

         indexTracker[x.second]+=1;

     }

       // -------- Output Part --------

     for( auto elements: ans ){
        cout<<elements<<" ";
     }

     cout<<endl;

   return 0;
}

/*

3
3
1 4 7
2
2 5
3
2 6 7

*/
