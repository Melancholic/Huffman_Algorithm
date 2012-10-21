#include"String.h"
#include<iostream>
#include<cmath>
string::string(){
  addStr();
  completion();
}

void string::setPoss(double a,int i){
   poss[i]+=a;
}

  void string::setLetters(char a,int i){
    letters[i]=a;
  }
void string::addPoss(double a){
 poss.push_back(a);
}
    

int string::getLengthStr(){
  return str.length();
}
void::string::show(){
  std::cout<<"\n      X: ";
for(int i=0;i<letters.size();i++){
  std::cout<<"  "<<letters[i];
}
  std::cout<<"\n   P(X): ";
for(int i=0;i<poss.size();i++){
  std::cout<<"  "<<poss[i];
}
  if(code.size()!=0){
      std::cout<<"\nCODE(X): ";
for(int i=0;i<code.size();i++){
  std::cout<<"  ";
  for(int j=0;j<code[i].size();++j){
    std::cout<<code[i].at(j);
  }
}
  std::cout<<"\n";
}

     std::cout<<"\nCODE Huffman: \n ";	
  for (int i=poss.size();i<tree.size();i++){
    std::cout<<tree[i].code<<" ";
    }
    
    std::cout<<"\nHX= "<<HX();
    std::cout<<"\nMLX= "<<MLX()<<"\n";
}

int string::getIndLetters(char a){
  if (letters.size()==0) return -1;
  for(int i=0;i<letters.size();++i){
    if (a==letters[i]){
      return i;
    }
  }
  return -1;
}
void string::addStr(){
  std::cout<<"\n Введите строку: ";
  if(std::cin>>str){
    std::cout<<"\nУспешный ввод. Длина строки: "<<str.length();
  }else{
    std::cout<<"\n Ошибка ввода";
  }
}
char string::getCharStr(int i){
  return str[i];
}
void string::addLetters(char a){
  letters.push_back(a);
}
void string::completion(){
  int j=0;
  double a =str.size();
   a=1/a;
    for(int i=0;i<str.size();i++){
    if(getIndLetters(str[i])>=0){
    setPoss(a,getIndLetters(str[i]));
      
    }else{

      addLetters(str[i]);
      addPoss(a);
      j++;
  }
  }
}

void string::sort(){
int l,j;
  l=poss.size()/2;
  while (l>0){
    for(int i=l;i<poss.size();i++){
      j=i-l;
      while(poss[j]>poss[j+l]){
	exchange(j,j+l);
	if(j<=l){
	  j=j-l;
	}else{
	  return;
	}
      }
      }
      l=l/2;
    }
	  
}

int string::getIndTreeMin(){
 double min=1;
 int old=-1;
 for(int i=0;i<tree.size();++i){
   if(tree[i].poss<min && !tree[i].tested && tree[i].poss!=0){
     min=tree[i].poss;
     old=i;
 }
 }
 tree[old].tested=true;
 return old;
}
 
   
 void string::makeTree(){
  int n=poss.size();
    tree.resize(n*2);
    for (int i=n;i<n*2;i++){
      tree[i].poss=poss[i-n];
      tree[i].letters=letters[i-n];
    }
     int a1,a2;
   int i=0;
    do{
   a1=getIndTreeMin();
   a2=getIndTreeMin();
   if(a1!=-1 &&a2!=-1){
    tree[i].poss=tree[a1].poss+tree[a2].poss;
    tree[i].letters=tree[a1].letters+tree[a2].letters;
    tree[i].left=&tree[a1];
    tree[i].right=&tree[a2];
    i++;
  }
    }while(a1!=-1 &&a2!=-1);
    for (int j=tree.size()-poss.size()-2;j>=0;--j){
    tree[j].left->code+=(tree[j].code+'0');
    tree[j].right->code+=(tree[j].code+'1');
    }
}

void string::exchange(int  a, int b){
  double tmp; 
  char tmps;
  tmp= poss[a];
  poss[a]=poss[b];
  poss[b]=tmp;
  tmps= letters[a];
  letters[a]=letters[b];
  letters[b]=tmps;
  
}

double string::MLX(){
  double sum=0;
  for(int i=0;i<poss.size();++i){
    sum+=poss[i]*tree[i+poss.size()].code.length();
  }
  return sum;
}

double string::HX(){
  double sum=0;
  for(int i=0;i<poss.size();++i){
    sum+=poss[i]*log(poss[i])/log(2)*(-1);
  }
  return sum;
}

node::node(){
  poss=0;
  letters="";
  code="";
  bool tested=false;
}