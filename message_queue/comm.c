#include "comm.h"

static int commMsgQueue(int flag)
{
  key_t _key = ftok(PATHNAME,PROJ_ID);
  if(_key < 0)
  {
    printf("ftok error\n");
    exit(1);
  }
  int msgid = msgget(_key,flag);
  if(msgid < 0)
  {
    printf("msgid error\n");
    exit(1);
  }
  return msgid;
}

int createMsgQueue()
{
  return commMsgQueue(IPC_CREAT|IPC_EXCL|0666);
}

int getMsgQueue()
{
  return commMsgQueue(IPC_CREAT);
}

int destoryMsgQueue(int msgid)
{
  if(msgctl(msgid,IPC_RMID,NULL)<0)
  {
    printf("msgclt error\n");
    exit(-1);
  }
  return 0;
}

int sendMsg(int msgid,int who,char *msg)
{
  struct msgbuf buf;
  buf.mtype = who;
  strcpy(buf.mtext,msg);
  if(msgsnd(msgid,(void*)&buf,sizeof(buf.mtext),0) <0 )
  {
    printf("sendMsg error\n");
    exit(-1);
  }
  return 0;
}

int recvMsg(int msgid,int recvType,char out[])
{
  struct msgbuf buf;
  if(msgrcv(msgid,(void*)&buf,sizeof(buf.mtext),recvType,0) < 0)
  {
    printf("recv error\n");
    exit(-1);
  }
  strcpy(out,buf.mtext);
  return 0;
}
