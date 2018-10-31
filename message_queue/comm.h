#pragma once

#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdlib.h>

#define PATHNAME "."
#define PROJ_ID 0x6666

#define SERVRT_TYPE 1
#define CLIENT_TYPE 2

struct msgbuf 
{
  long mtype;
  char mtext[1024];
};

int createMsgQueue();
int grtMsgQueue();
int destoryMsgQueue(int msgid);
int sendMsg(int msgid,int who,char* msg);
int recvMsg(int msgid,int recvType,char our[]);
