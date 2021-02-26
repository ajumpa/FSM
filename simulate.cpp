#include "VFSM.h"
#include "verilated.h"
#include <iostream>;

using namespace std;
int main(int argc, char **argv)
{
  Verilated::commandArgs(argc, argv);
  VFSM* fsm = new VFSM;
  while (!Verilated::gotFinish()) 
  { 

  /*module FSM(input clk, 
           input reset, 
           input left, 
           input right,
           */
    fsm->clk = 0;
    fsm->reset = 0;
    fsm->left = 1;
    fsm->right = 0;
    fsm->eval();
    sleep(3);

    fsm->clk = 1;
    fsm->reset = 0;
    fsm->left = 1;
    fsm->right = 0;
    fsm->eval();
    sleep(3);

    fsm->clk = 0;
    fsm->reset = 0;
    fsm->left = 1;
    fsm->right = 0;
    fsm->eval();
    sleep(3);

    fsm->clk = 1;
    fsm->reset = 0;
    fsm->left = 1;
    fsm->right = 0;
    fsm->eval();
    sleep(3);

    fsm->clk = 0;
    fsm->reset = 0;
    fsm->left = 1;
    fsm->right = 0;
    fsm->eval();
    sleep(3);

    fsm->clk = 1;
    fsm->reset = 0;
    fsm->left = 1;
    fsm->right = 0;
    fsm->eval();
    sleep(3);

    fsm->clk = 0;
    fsm->reset = 0;
    fsm->left = 1;
    fsm->right = 0;
    fsm->eval();
    sleep(3);

    fsm->clk = 1;
    fsm->reset = 0;
    fsm->left = 1;
    fsm->right = 0;
    fsm->eval();
    sleep(3);

    fsm->clk = 0;
    fsm->reset = 0;
    fsm->left = 1;
    fsm->right = 0;
    fsm->eval();
    sleep(3);

    fsm->clk = 1;
    fsm->reset = 0;
    fsm->left = 1;
    fsm->right = 0;
    fsm->eval();
    sleep(3);

    fsm->clk = 0;
    fsm->reset = 0;
    fsm->left = 1;
    fsm->right = 0;
    fsm->eval();
    sleep(3);

    fsm->clk = 1;
    fsm->reset = 0;
    fsm->left = 1;
    fsm->right = 0;
    fsm->eval();
    sleep(3);
  }

  delete fsm;
  exit(0);
}