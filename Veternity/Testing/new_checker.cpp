#include "testlib.h"
 
using namespace std;
 
set<pair<int,int>> readEdge(InStream& In){
  set<pair<int,int>> edge;
  int n = In.readInt();
  In.readEoln();
  for(int i = 0; i<n; i++){
    int u = In.readInt();
    In.readSpace();
    int v = In.readInt();
    In.readEoln();
    if(u > v) swap(u,v);
    if(edge.find({u,v}) != edge.end()){
      quitf(_wa, "Duplicate Edge %d %d", u,v);
    }
    edge.insert({u,v});

  }
  if(!In.seekEof()){
    quitf(_wa, "Found Extra Edge");
  }
  return edge;
}

int main(int argc, char * argv[])
{
  setName("compare sequences of tokens");
  registerTestlibCmd(argc, argv);
  auto Juri = readEdge(ans);
  auto Jawaban = readEdge(ouf);
  if(Juri == Jawaban){
    quitf(_ok, "Jawaban Sesuai");
  }else{
    quitf(_wa, "Jawaban Tidak Sesuai");
  }
}
