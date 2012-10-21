#ifndef STRING_H
#define STRING_H
#include<vector>
#include<string>
struct node{
  double poss;
  std::string letters;
  std::string code;
  bool tested;
  node* right;
  node* left;
  node();
};
  
class string{
  std::vector<node> tree;
  std::string str;
  std::vector<char> letters;
  std::vector<double> poss;
  std::vector<std::string> code;
  double MLX();
  double HX();
  void addStr();
  void completion();
  char getCharStr(int i);
  int getLengthStr();
  void addLetters(char a);
  void setLetters(char a,int i);
  int getIndLetters(char a);
  char getLetters(int i);
  void addPoss(double a);
  void setPoss(double a,int i);
  double getPoss(int i);
  void exchange(int  a, int b);
  int getIndTreeMin();
public:
  string();
  void sort();
  void show();
  void makeTree();
};
#endif