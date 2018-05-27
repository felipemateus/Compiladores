#include <string>
#include <list>
#include <map>

using namespace std;

class exp_node{
public:
  int num;

  virtual void print() = 0;

  virtual int evaluate() = 0;
};

class operator_node : public exp_node{
public:
  exp_node *left;
  exp_node *right;

  operator_node(exp_node *L,exp_node *R);
};


class plus_node: public operator_node{
public:
  plus_node(exp_node *L,exp_node *R);
  void print();
  int evaluate();
};


class number_node: public exp_node{
public:
  number_node(int number);
  void print();
  int evaluate();
};


class calc{
protected:
    exp_node *node;

  public:
    calc(exp_node *node);
    void evaluate();
};