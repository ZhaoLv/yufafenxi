//LexAnalysis.cpp

#include "LexAnalysis.h"

using namespace std;

port * PortHead;//端口首结点
transaction * TranHead;
function* FunHead;
constraint * ConHead;
//boundry_condition * BounHead;
/*boundry_condition* BounHead;*/


void initNode()
{
    PortHead = new port();
    strcpy(PortHead->id ,"");
	PortHead->direction = -1;
	PortHead->width= -1;
	PortHead->next=NULL;

	TranHead = new transaction();
	strcpy(TranHead->id , "");
	strcpy(TranHead->t , "");
	TranHead->next=NULL;

	FunHead = new function();
	strcpy(FunHead->condition, "");
	strcpy(FunHead->action, "");
	strcpy(FunHead->configuration, "");
	for(int i=0;i<10;i++)
	{
		strcpy(FunHead->boundry_condition[i],"");
	}
	FunHead->i=-1;
	FunHead->next=NULL;
	/*
	BounHead = new boundry_condition();
	BounHead->f=NULL;
	for(int i=0;i<10;i++)
	{
		strcpy(BounHead->condition[i],"");
	}
	BounHead->i=-1;
	BounHead->next=NULL;
	*/
}

void createport(char* id, int direct, int width)
{
	port * p=PortHead;
	port * temp = new port();
	while(p->next!=NULL)
	{
		p=p->next;
	}
	strcpy(temp->id,id);
	temp->direction=direct;
	temp->width=width;
	p->next=temp;
	
}
void close()
{
    delete PortHead;
	delete TranHead;
	delete FunHead;
	delete ConHead;
}

void errorport(int line)
{
//	char ff[10];
	printf("错误在第%d行\n",line);
//	scanf("%s",ff);
}
void  printport()
{
	port * p=PortHead;
	while(p->next!=NULL)
	{
		p=p->next;
		cout<<p->id<<p->direction<<p->width<<endl;

	}
	int i;
	cin>>i;
}

void scanner_port()
{
	char filename[30];
	char ch;
	char * key;
	char array[30];
	int line;
	line = 1;
    FILE * infile;
    printf("请输入要进行端口文件分析的功能模型程序：\n");
    scanf("%s",filename);
    infile = fopen(filename,"r");
    while(!infile)
    {
        printf("打开文件失败！\n");
        return;
    }
    ch = fgetc(infile);

    while(ch!=EOF)
    {
		if(ch=='\n')
		{
			line++;
			ch=fgetc(infile);
		}
		else
		{
			int k=0;
			while(ch!=' ')
			{
				array [k++] = ch;
				ch = fgetc(infile);
			}
			key = new char[k+1];
			memcpy(key, array, k);
			key[k] = '\0';
			if(strcmp(key,"port")==0)
			{
			
				char* id;
				int direct;
				int width;
				char* temp_direct;
				char* temp_width;
				k=0;
				ch = fgetc(infile);
				while(ch!='(')
				{
					array [k++] = ch;
					ch = fgetc(infile);
				}
				id = new char[k+1];
				memcpy(id, array, k);
				id[k] = '\0';
				ch = fgetc(infile);
				k=0;
				while(ch!=',')
				{
					array [k++] = ch;
					ch = fgetc(infile);
				}
				temp_direct = new char[k+1];
				memcpy(temp_direct,array,k);
				temp_direct[k]='\0';
				direct=atoi(temp_direct);
				ch = fgetc(infile);
				k=0;
				while(ch!=')')
				{
					array [k++] = ch;
					ch = fgetc(infile);
				}
				temp_width = new char[k+1];
				memcpy(temp_width,array,k);
				temp_width[k]='\0';
				width=atoi(temp_width);
				createport(id,direct,width);
				ch = fgetc(infile);
			}
			else 
				
			{
				errorport(line);
				break;
			}

		}
	}
}

void createtransaction(char* id, char* t)
{
	transaction * p=TranHead;
	transaction * temp = new transaction();
	while(p->next!=NULL)
	{
		p=p->next;
	}
	strcpy(temp->id,id);
	strcpy(temp->t,t);
	p->next=temp;
	
}

void errortransaction(int line)
{
//	char ff[10];
	printf("错误在第%d行\n",line);
//	scanf("%s",ff);
}

void  printtransaction()
{
	transaction * p=TranHead;
	while(p->next!=NULL)
	{
		p=p->next;
		cout<<p->id<<endl<<p->t<<endl;

	}
	int i;
	cin>>i;
}
void errorfunction(int line)
{
	printf("错误在第%d行\n",line);
}

void scanner_transaction()
{
	char filename[30];
	char ch;
	char * key;
	char array[200];
	int line;
	line = 1;
    FILE * infile;
    printf("请输入要进行事务文件分析的功能模型程序：\n");
    scanf("%s",filename);
    infile = fopen(filename,"r");
    while(!infile)
    {
        printf("打开文件失败！\n");
        return;
    }
    ch = fgetc(infile);

    while(ch!=EOF)
    {
		if(ch=='\n')
		{
			line++;
			ch=fgetc(infile);
		}
		else
		{
			int k=0;
			while(ch!=' ')
			{
				array [k++] = ch;
				ch = fgetc(infile);
			}
			key = new char[k+1];
			memcpy(key, array, k);
			key[k] = '\0';
			if(strcmp(key,"transaction")==0)
			{
			
				char* id;
				char* t;
				k=0;
				ch=fgetc(infile);
				while(ch!='=')
				{
					array [k++] = ch;
					ch = fgetc(infile);
				}
				id = new char[k+1];
				memcpy(id, array, k);
				id[k] = '\0';
				ch = fgetc(infile);
				k=0;
				while((ch!='\n')&& (ch!=EOF))
				{
					array [k++] = ch;
					ch = fgetc(infile);
				}
				t = new char[k+1];
				memcpy(t,array,k);
				t[k]='\0';
				createtransaction(id, t);
			}
			else 
			{
				errortransaction(line);
				break;
			}

		}
	}
}

void createfunction(char* id, char* condition, char* action, char* configuration,function* pre)
{
	function * p=FunHead;
	function * temp = new function();
	while(p->next!=NULL)
	{
		p=p->next;
	}
	strcpy(temp->id,id);
	strcpy(temp->condition,condition);
	strcpy(temp->action,action);
	strcpy(temp->configuration,configuration);
	temp->pre=pre;
	
	
	
	//这里加产生condition_boundry,i
	temp->i=0;
	int condition_length=mystrlen(condition);
	for(int k=0;k<condition_length;k++)
	{
		char * condition_temp;
		condition_temp= condition;
		if((condition[k]=='>')||(condition[k]=='<'))
		{
			for(int m=k;m<mystrlen(condition_temp);m++)
			{
			//替换最近的一个
				if((condition_temp[m]=='>')||(condition_temp[m]=='<'))
				{
					if(condition_temp[m+1]!='=')
					{
						memcpy(temp->boundry_condition[temp->i],condition_temp,mystrlen(condition_temp)+1);
						temp->boundry_condition[temp->i][mystrlen(condition_temp)]='\0';
						temp->boundry_condition[temp->i][m]='=';
						for(int n=mystrlen(condition_temp); n>m;n--)
						{
							temp->boundry_condition[temp->i][n+1]=temp->boundry_condition[temp->i][n];
						}
						temp->boundry_condition[temp->i][m+1]='=';
						condition_temp = temp->boundry_condition[temp->i];
						temp->i=temp->i+1;
					}
					else if(condition_temp[m+1]=='=')
					{
						memcpy(temp->boundry_condition[temp->i],condition_temp,mystrlen(condition_temp)+1);
						temp->boundry_condition[temp->i][mystrlen(condition_temp)]='\0';
						temp->boundry_condition[temp->i][m]='=';
						condition_temp = temp->boundry_condition[temp->i];
						temp->i=temp->i+1;
					}
				}
			}
		}
	}

	p->next=temp;
}     
            
void  printfunction()
{
	function * p=FunHead;
	while(p->next!=NULL)
	{
		p=p->next;
		cout<<p->id<<endl<<p->condition<<endl<<p->configuration<<endl<<p->action<<endl;
		for(int k=0;k<p->i;k++)
		{
			cout<<p->boundry_condition[k]<<endl;
		}
		if(p->pre!=NULL)
		{
			cout<<p->pre->id<<endl;
		}

	}
	int i;
	cin>>i;
}
function * functionsearch(char * id)
{
	function * p=FunHead;
	while(p->next!=NULL)
	{
		p=p->next;
		if(strcmp(p->id,id)==0)
		{
			return p;
		}
	}
	return NULL;
}
char * findtransaction(char * word)
{
	transaction * p = TranHead;
	while(p->next!=NULL)
	{
		p=p->next;
		if(strcmp(p->id,word)==0)
		{
			return p->t;
		}

	}
	return NULL;
}
/*
function* findfunction(char * id)
{
	function * p=FunHead;
	while(p->next)
*/


unfold * unfoldcondition(char* condition)
{
	unfold * f = new unfold();
	f->pre==NULL;
	strcpy(f->condition,"");
	char constraint[500];
	strcpy(constraint,"");
	int i;
	char array[500];
	char * word;
	int condition_length = mystrlen(condition);
//		char* c = condition;
	for(i=0;i<condition_length;i++)
	{
		if((condition[i]>='A' && condition[i]<='Z') || (condition[i]>='a' && condition[i]<='z') || (condition[i]>='0' && condition[i]<='9')||condition[i] == '_')
		{
			int k=0;
				//array="";
			while((condition[i]>='A' && condition[i]<='Z') || (condition[i]>='a' && condition[i]<='z') || (condition[i]>='0' && condition[i]<='9')|| condition[i] == '_')
			{
				array[k++] = condition[i++];
			}
			word = new char[k+1];
			memcpy(word,array,k);
			word[k] = '\0';
			if(functionsearch(word)!=NULL)
			{
				f->pre=functionsearch(word);
				i=i+1;//不要把先行功能后面跟着那个“；”加进constraint里面。
			}
			else if(findtransaction(word)!=NULL)
			{
				strcat(constraint , findtransaction(word));
			}
			else
				strcat(constraint,word);
			i=i-1;
		}
		else
		{
			word = new char[2];
			word[0]=condition[i];
			word[1]='\0';
			strcat(constraint,word);
		}
	}
	strcpy(f->condition,constraint);
	return f;
}

/*
					strcat(constraint ,functionsearch(word)->condition);
					//加时间。。。方法2
					char * action_temp = new char [mystrlen(functionsearch(word)->action)+1];
					memcpy(action_temp,(functionsearch(word)->action),mystrlen(functionsearch(word)->action));
					action_temp[mystrlen(functionsearch(word)->action)]='\0';
					char* token = strtok(action_temp,"#;");
					int time=0;
					time=time+OPERTIME;
					while(token!=NULL)
					{
						int m=0;
						int mark=0;
						while(token[m]!='\0')
						{
							if(token[m]>'9'||token[m]<'0')
								mark=1;
							m++;
						}
						if(mark==0)
						{
							time = time + atoi(token);
						}
						token = strtok(NULL,"#;");
					}
					char opertime[15];
					opertime[0]='#';
					opertime[1]='\0';
					char time_temp[13];
					itoa(time,time_temp,10);
					strcat(opertime,time_temp);
					strcat(constraint,opertime);
					*/
				
	
						/*
						//加时间，方法3
					char opertime[15];
					opertime[0]='#';
					opertime[1]='\0';
					char time[13];
					int time_num=OPERTIME;
					itoa(time_num,time,10);
					strcat(opertime,time);//默认间隔了一个执行时间
					//strcat(opertime,";");
					strcat(constraint, opertime);
					

				}
				*/
char * unfoldaction(char* action)
{
	char * unfoldaction = new char [1000];
	strcpy(unfoldaction,"");
	int i;
	char array[500];
	char * word;
	int action_length = mystrlen(action);
	for(i=0;i<action_length;i++)
	{
		if((action[i]>='A' && action[i]<='Z') || (action[i]>='a' && action[i]<='z') || (action[i]>='0' && action[i]<='9')||action[i] == '_')
		{
			int k=0;
				//array="";
			while((action[i]>='A' && action[i]<='Z') || (action[i]>='a' && action[i]<='z') || (action[i]>='0' && action[i]<='9')|| action[i] == '_')
			{
				array[k++] = action[i++];
			}
			word = new char[k+1];
			memcpy(word,array,k);
			word[k] = '\0';
			if(findtransaction(word)!=NULL)
			{
				strcat(unfoldaction , findtransaction(word));
			}
			else
				strcat(unfoldaction,word);
			i=i-1;
		}
		else
		{
			word = new char[2];
			word[0]=action[i];
			word[1]='\0';
			strcat(unfoldaction,word);
		}
	}
	return unfoldaction;
}





void scanner_function()
{
	char filename[30];
	char ch;
	char * key;
	char array[500];
	int line;
	line = 1;
    FILE * infile;
    printf("请输入要进行功能文件分析的功能模型程序：\n");
    scanf("%s",filename);
    infile = fopen(filename,"r");
    while(!infile)
    {
        printf("打开文件失败！\n");
        return;
    }
    ch = fgetc(infile);

    while(ch!=EOF)
    {
		if(ch=='\n')
		{
			line++;
			ch=fgetc(infile);
		}
		else
		{
			int k=0;
			while(ch!=' ')
			{
				array [k++] = ch;
				ch = fgetc(infile);
			}
			key = new char[k+1];
			memcpy(key, array, k);
			key[k] = '\0';
			if(strcmp(key,"function")==0)
			{
			
				ch=fgetc(infile);
				char* id;
				char* condition;
				char* action;
				char* configuration;
				k=0;
				while((ch!='{')&&(ch!=' '))
				{
					array [k++] = ch;
					ch = fgetc(infile);
				}
				id = new char[k+1];
				memcpy(id, array, k);
				id[k] = '\0';
				if(ch=='{')
				{
					ch = fgetc(infile);
					if(ch!='\n')
					{
						errorfunction(line);
						break;
					}
					else
					{
						line++;
						ch = fgetc(infile);
						while((ch!='}')&&(ch!=EOF))
						{
							k=0;
							char* temp;
							while(ch!='=')
							{
							array [k++] = ch;
							ch = fgetc(infile);
							}
							temp = new char[k+1];
							memcpy(temp,array,k);
							temp[k]='\0';
							if(strcmp(temp,"condition")==0)
							{
								ch=fgetc(infile);
								k=0;
								while(ch!='\n')
								{
									array [k++] = ch;
									ch = fgetc(infile);
								}
								condition = new char[k+1];
								memcpy(condition,array,k);
								condition[k]='\0';
								line++;
							}
							else if(strcmp(temp,"action")==0)
							{
								ch=fgetc(infile);
								k=0;
								while(ch!='\n')
								{
									array [k++] = ch;
									ch = fgetc(infile);
								}
								action = new char[k+1];
								memcpy(action,array,k);
								action[k]='\0';
								line++;
							}
							else if(strcmp(temp,"configuration")==0)
							{
								ch=fgetc(infile);
								k=0;
								while(ch!='\n')
								{
									array [k++] = ch;
									ch = fgetc(infile);
								}
								configuration = new char[k+1];
								memcpy(configuration,array,k);
								configuration[k]='\0';
								line++;
							}
							else 
							{
								errorfunction(line);
								break;
							}
							ch = fgetc(infile);
							delete temp;
						}
						
						

						createfunction(id,unfoldcondition(condition)->condition,unfoldaction(action),configuration,unfoldcondition(condition)->pre);

					}
				}
				else if (ch==' ')
				{
					k=0;
					ch=fgetc(infile);
					if (ch==':')
					{
						ch=fgetc(infile);
						while(ch!='{')
						{
							array [k++] = ch;
							ch = fgetc(infile);
						}
						char * fatherid;
						fatherid = new char[k+1];
						memcpy(fatherid,array,k);
						fatherid[k]='\0';
						if(functionsearch(fatherid)==NULL)
						{
							errorfunction(line);
							break;
						}
						else
						{
							condition = new char [500];
							action = new char [500];
							configuration = new char[100];
							function * father = functionsearch(fatherid);
							memcpy(condition,father->condition,mystrlen(father->condition));
							memcpy(action,father->action,mystrlen(father->action));
							memcpy(configuration,father->configuration,mystrlen(father->configuration));
							condition[mystrlen(father->condition)]='\0';
							action[mystrlen(father->action)]='\0';
							configuration[mystrlen(father->configuration)]='\0';
							ch = fgetc(infile);
							if(ch!='\n')
							{
								errorfunction(line);
								break;
							}
							else
							{
								line++;
								ch = fgetc(infile);
								while((ch!='}')&&(ch!=EOF))
								{
									k=0;
									char* temp;
									while(ch!='=')
									{
									array [k++] = ch;
									ch = fgetc(infile);
									}
									temp = new char[k+1];
									memcpy(temp,array,k);
									temp[k]='\0';
									if(strcmp(temp,"condition")==0)
									{
										ch=fgetc(infile);
										k=0;
										while(ch!='\n')
										{
											array [k++] = ch;
											ch = fgetc(infile);
										}
										//condition = new char[k+1];
										array[k]='\0';
										strcat(condition,array);
										//condition[k]='\0';
										line++;
									}
									else if(strcmp(temp,"action")==0)
									{
										ch=fgetc(infile);
										k=0;
										while(ch!='\n')
										{
											array [k++] = ch;
											ch = fgetc(infile);
										}
										//action = new char[k+1];
										array[k]='\0';
										strcat(action,array);
										//action[k]='\0';
										line++;
									}
									else if(strcmp(temp,"configuration")==0)
									{
										ch=fgetc(infile);
										k=0;
										while(ch!='\n')
										{
											array [k++] = ch;
											ch = fgetc(infile);
										}
										//configuration = new char[k+1];
										array[k]='\0';
										strcat(configuration,array);
										//configuration[k]='\0';
										line++;
									}
									else 
									{
										errorfunction(line);
										break;
									}
									ch = fgetc(infile);
									delete temp;
								}
								createfunction(id,(unfoldcondition(condition))->condition,unfoldaction(action),configuration,(unfoldcondition(condition))->pre);
							}
						}
					}
					else
					{
						errorfunction(line);
						break;
					}
			}
			else
			{
				errorfunction(line);
				break;
			}
			ch = fgetc(infile);
		}
		else 
		{
			errorfunction(line);
				break;
		}
		
	}
	}
	return;
}
/*
void scanner_boundry_condition(function* f)
{

}

void printboundrysv()
{

}
*/

int mystrlen(char * word)
{
    if(*word == '\0')
    {
        return 0;
    }
    else
    {
        return 1+mystrlen(word+1);
    }
}
bool findconfiguration(function * f,port * p)
{
	int i=mystrlen(f->configuration);
	char* word;
	word=new char[i+1];
	memcpy(word,f->configuration ,i);
	word[i]='\0';
	char* token = strtok( word, ",");
	while(token!=NULL)
	{
		if(strcmp(p->id,token)==0)
			return true;
		token = strtok( NULL, ",");

	}
	return false;
}


		





void printsv()//每一个功能点都输出一个.sv
{
	function * f = FunHead;
	int o=0;
	while(f->next!=NULL)
	{
		f=f->next;
		char name[30];
		memcpy(name,f->id,mystrlen(f->id));
		name[mystrlen(f->id)]='\0';
		strcat(name,".sv");
		ofstream ofile;
		ofile.open(name,ios::app);
		ofile<<"`timescale "<<TIMEUNIT<<" / "<<TIMEPRECISION<<endl;
		ofile<<"module test"<<o<<";"<<endl;



		// port写
		port * p = PortHead;
		while(p->next!=NULL)
		{
			p=p->next;
			if(p->direction==1)
			{
				ofile<<"reg"<<"  ";
			}	
			else
			{
				ofile<<"wire"<<"  ";
			}
			if(p->width>1)
			{
				ofile<<"["<<(p->width-1)<<":"<<"0"<<"]";
			}
			ofile<<p->id<<";"<<endl;
		}	
		//展开约束,写类
	
		int o=0;//区分不同类
		ofile<<"class packet"<<";"<<endl;
		p=PortHead;
		while(p->next!=NULL)
		{
			p=p->next;
			if(strcmp(p->id,"clk")==1)
			{
				if(p->direction==1)
				{
					if(findconfiguration(f,p))
					{
						ofile<<"randc"<<" "<<"bit"<<" ";
					}
					else
					{
						ofile<<"rand"<<" "<<"bit"<<" ";
					}
					if(p->width>1)
					{
						ofile<<"["<<(p->width-1)<<":"<<"0"<<"]";
					}
					ofile<<p->id<<";"<<endl;
				}
			}
		}
		/*
		//展开约束
		strcpy(constraint,"");
		int i;
		char array[500];
		char * word;
		int condition_length = mystrlen(f->condition);
		char* c = f->condition;
		for(i=0;i<condition_length;i++)
		{
			if((c[i]>='A' && c[i]<='Z') || (c[i]>='a' && c[i]<='z') || c[i] == '_')//事务的名字不支持出现数字,这一段是将调用的事务展开的
			{
				int k=0;
				//array="";
				while((c[i]>='A' && c[i]<='Z') || (c[i]>='a' && c[i]<='z') || c[i] == '_')
				{
					array[k++] = c[i++];
				}
				word = new char[k+1];
				memcpy(word,array,k);
				word[k] = '\0';
				if(findtransaction(word)!=NULL)
				{
					strcat(constraint , findtransaction(word));
				}
				else
					strcat(constraint,word);
				i=i-1;
			}
			else
			{
				word = new char[2];
				word[0]=c[i];
				word[1]='\0';
				strcat(constraint,word);
			}
		}
		*/

		//这一段是将时序的问题展开,思想是将带有#之前的放在constraint之中，其他的就直接写在后面，作为一次功能的激励
		char * constraint;
		constraint = (f->condition);
		int i=0;
		int m=0;
		int n=0;
		char constraint_class[500];
		char constraint_time[500];
		while(constraint[i]!='#'&& constraint[i]!='\0')
		{
			constraint_class[m++]=constraint[i++];
		}
		constraint_class[m]='\0';
		if(constraint[i]=='#')
		{
			while(constraint[i]!='\0')
			{
				constraint_time[n++]=constraint[i++];
			}
		}
		constraint_time[n]='\0';
		//写类中的约束：
		ofile<<"constraint  "<<f->id<<"{"<<endl;
		ofile<<constraint_class<<endl;
		ofile<<"}"<<endl;
		ofile<<"endclass"<<endl;
		o++;
		//实例化
		ofile<<"fpu "<<"ins1 "<<"("<<endl;
		p=PortHead;
		while(p->next!=NULL)
		{
			p=p->next;
			if(p->next!=NULL)
			{
				ofile<<"."<<p->id<<"("<<p->id<<")"<<","<<endl;
			}
			else
				ofile<<"."<<p->id<<"("<<p->id<<")"<<endl;
		}
		ofile<<");"<<endl;

		//实例化类packet
		ofile<<"packet p;"<<endl;

		//开始激励平台赋值主体：
		ofile<<"initial"<<endl;
		ofile<<"begin"<<endl;
		ofile<<"p=new();"<<endl;
		ofile<<"#0"<<endl;
		ofile<<RSTSIGNAL<<" = 1'b1;"<<endl;//初始化不一样，这个信号变不一样。
		ofile<<"# "<<RSTTIME<<";"<<endl;//设置的初始化执行时间
		ofile<<"repeat("<<COUNT<<")"<<endl;
		ofile<<"begin"<<endl;
		ofile<<"assert(p.randomize());"<<endl;
		p=PortHead;
		while(p->next!=NULL)
		{
			p=p->next;
			if(strcmp(p->id,"clk")==1)
			{
				if(p->direction==1)
				{
					ofile<<p->id<<"="<<"p."<<p->id<<";"<<endl;
				}
			}
		}
		ofile<<constraint_time<<endl;
		ofile<<"# "<<OPERTIME<<";"<<endl;//功能的延时
		//display所有的信号值
		p=PortHead;
		while(p->next!=NULL)
		{
			p=p->next;
			if(strcmp(p->id,"clk")==1)
			{
				ofile<<"$display("<<"\""<<p->id<<"="<<"%b"<<"\""<<","<<p->id<<");"<<endl;
			}
				
		}
		ofile<<"end"<<endl;
		for(int k=0;k<f->i;k++)
		{
			ofile<<"repeat("<<COUNT<<")"<<endl;
			ofile<<"begin"<<endl;
			ofile<<"p.constraint_mode(0);"<<endl;
			//char * constraint;
			constraint = (f->boundry_condition[k]);
			i=0;
			m=0;
			n=0;
			//char constraint_class[500];
			//char constraint_time[500];
			while(constraint[i]!='#'&& constraint[i]!='\0')
			{
				constraint_class[m++]=constraint[i++];
			}
			constraint_class[m]='\0';
			if(constraint[i]=='#')
			{
				while(constraint[i]!='\0')
				{
					constraint_time[n++]=constraint[i++];
				}
			}
			constraint_time[n]='\0';
			ofile<<"assert(p.randomize()with{"<<constraint_class<<"});"<<endl;
			p=PortHead;
			while(p->next!=NULL)
			{
				p=p->next;
				if(strcmp(p->id,"clk")==1)
				{
					if(p->direction==1)
					{
						ofile<<p->id<<"="<<"p."<<p->id<<";"<<endl;
					}
				}
			}
			ofile<<constraint_time<<endl;
			ofile<<"# "<<OPERTIME<<";"<<endl;//功能的延时
			//display所有的信号值
			p=PortHead;
			while(p->next!=NULL)
			{
				p=p->next;
				if(strcmp(p->id,"clk")==1)
				{
					ofile<<"$display("<<"\""<<p->id<<"="<<"%b"<<"\""<<","<<p->id<<");"<<endl;
				}
				
			}
			ofile<<"end"<<endl;	
		}
		ofile<<"$finish;"<<endl;
		ofile<<"end"<<endl;

		//设时钟
		ofile<<"always"<<endl;
		ofile<<"begin : CLOCK_clk"<<endl;
		ofile<<"clk = 1'b0;"<<endl;
		ofile<<"#"<<CLKTIME<<";"<<endl;
		ofile<<"clk = 1'b1;"<<endl;
		ofile<<"#"<<CLKTIME<<";"<<endl;
		ofile<<"end"<<endl;
		ofile<<"endmodule"<<endl;
		ofile.close();
	}	
}
/*
int replace_nearest(char* sSrc, char* sMatchStr, char* sReplaceStr, char* caNewString)
{
	 int StringLen;
    // char caNewString[500];
     char* FindPos;
     FindPos =(char *)strstr(sSrc, sMatchStr);
     if( (!FindPos) || (!sMatchStr) )
		return -1;
	 else
	 {
        //memset(caNewString, 0, sizeof(caNewString));
        StringLen = FindPos - sSrc;
        memcpy(caNewString, sSrc, StringLen+1);
		caNewString[StringLen] = '\0';
        strcat(caNewString, sReplaceStr);
        strcat(caNewString, FindPos + strlen(sMatchStr));
        //strcpy(sSrc, caNewString);
        //free(FindPos);
        return 0;
	 }
}

*/
/*

void createboundry_condition(function * f)
{
	boundry_condition * b= BounHead;
	boundry_condition * temp = new boundry_condition();
	while(b->next!=NULL)
	{
		b=b->next;
	}
	temp->f=f;
	temp->i=0;
	char * original=f->condition;
	int condition_length=mystrlen(original);
	if(replace_nearest(original, ">", "==", NULL))
//	temp->condition[temp->i] = replace_nearest(original, ">", "==");







	for (int k=0;k<condition_length;k++)
	{
		if(((original[k]=='>')&&(original[k+1]!='='))||((original[k]=='<')&&(original[k+1]!='=')))
		{
			memcpy(temp->condition[temp->i],original,condition_length+1);
			temp->condition[temp->i][condition_length]='\0';
			temp->condition[temp->i][k]='=';
			for(int m=condition_length; m>k;m--)
			{
				temp->condition[temp->i][m+1]=temp->condition[temp->i][m];
			}
			temp->condition[temp->i][k+1]='=';
			temp->i=temp->i+1;
		}
		else if(((original[k]=='>')&&(original[k+1]!='='))||((original[k]=='<')&&(original[k+1]!='=')))
		{
			memcpy(temp->condition[temp->i],original,condition_length+1);
			temp->condition[temp->i][condition_length]='\0';
			temp->condition[temp->i][k]='=';
			temp->i=temp->i+1;
		}	
	}
	b->next=temp;
}

void print_boundry_condition()
{
	function * p=FunHead;
	while(p->next!=NULL)
	{
		p=p->next;
		createboundry_condition(p);
	}
	boundry_condition * b= BounHead;
	while(b->next!=NULL)
	{
		b=b->next;
		cout<<b->f->id<<endl;
		for(int k=0;k<b->i;k++)
		{
			cout<<b->condition[k];
		}
	}
	int i;
	cin>>i;
}
void print_boundrysv()
{
	function * p=FunHead;
	while(p->next!=NULL)
	{
		p=p->next;
		createboundry_condition(p);
	}
	
	boundry_condition * b= BounHead;
	int o=0;
	while(b->next!=NULL)
	{
		b=b->next;
		char name[30];
		memcpy(name,b->f->id,mystrlen(b->f->id));
		name[mystrlen(b->f->id)]='\0';
		strcat(name,"_boundry.sv");
		ofstream ofile;
		ofile.open(name,ios::app);
		ofile<<"`timescale "<<TIMEUNIT<<" / "<<TIMEPRECISION<<endl;
		ofile<<"module test_b_"<<o<<";"<<endl;
		port * p = PortHead;
		while(p->next!=NULL)
		{
			p=p->next;
			if(p->direction==1)
			{
				ofile<<"reg"<<"  ";
			}	
			else
			{
				ofile<<"wire"<<"  ";
			}
			if(p->width>1)
			{
				ofile<<"["<<(p->width-1)<<":"<<"0"<<"]";
			}
			ofile<<p->id<<";"<<endl;
		}	
		//展开约束,写类
	
		int o=0;//区分不同类
		ofile<<"class packet"<<";"<<endl;
		p=PortHead;
		while(p->next!=NULL)
		{
			p=p->next;
			if(strcmp(p->id,"clk")==1)
			{
				if(p->direction==1)
				{
					if(findconfiguration(b->f,p))
					{
						ofile<<"randc"<<" "<<"bit"<<" ";
					}
					else
					{
						ofile<<"rand"<<" "<<"bit"<<" ";
					}
					if(p->width>1)
					{
						ofile<<"["<<(p->width-1)<<":"<<"0"<<"]";
					}
					ofile<<p->id<<";"<<endl;
				}
			}
		}
		ofile<<"endclass"<<endl;
		ofile<<"fpu "<<"ins1 "<<"("<<endl;
		p=PortHead;
		while(p->next!=NULL)
		{
			p=p->next;
			if(p->next!=NULL)
			{
				ofile<<"."<<p->id<<"("<<p->id<<")"<<","<<endl;
			}
			else
				ofile<<"."<<p->id<<"("<<p->id<<")"<<endl;
		}
		ofile<<");"<<endl;

		//实例化类packet
		ofile<<"packet p;"<<endl;

		//开始激励平台赋值主体：
		ofile<<"initial"<<endl;
		ofile<<"begin"<<endl;
		ofile<<"p=new();"<<endl;
		ofile<<"#0"<<endl;
		ofile<<RSTSIGNAL<<" = 1'b1;"<<endl;//初始化不一样，这个信号变不一样。
		ofile<<"# "<<RSTTIME<<";"<<endl;//设置的初始化执行时间
		//开始逐一进行约束
		for(int k=0;k<b->i;k++)
		{
			ofile<<"repeat("<<COUNT<<")"<<endl;
			ofile<<"begin"<<endl;
			char * constraint;
			constraint = b->condition[k];
			int i=0;
			int m=0;
			int n=0;
			char constraint_class[500];
			char constraint_time[500];
			while(constraint[i]!='#'&& constraint[i]!='\0')
			{
				constraint_class[m++]=constraint[i++];
			}
			constraint_class[m]='\0';
			if(constraint[i]=='#')
			{
				while(constraint[i]!='\0')
				{
					constraint_time[n++]=constraint[i++];
					}
			}
			constraint_time[n]='\0';


			ofile<<"assert(p.randomize()"<<"with{"<<constraint_class<<"}"<<");"<<endl;
			p=PortHead;
			while(p->next!=NULL)
			{
				p=p->next;
				if(strcmp(p->id,"clk")==1)
				{
					if(p->direction==1)
					{
						ofile<<p->id<<"="<<"p."<<p->id<<";"<<endl;
					}
				}
			}
			ofile<<constraint_time<<endl;
			ofile<<"# "<<OPERTIME<<";"<<endl;//功能的延时
			//display所有的信号值
			p=PortHead;
			while(p->next!=NULL)
			{
				p=p->next;
				if(strcmp(p->id,"clk")==1)
				{
					ofile<<"$display("<<"\""<<p->id<<"="<<"%b"<<"\""<<","<<p->id<<");"<<endl;
				}
				
			}
			ofile<<"end"<<endl;
		}
		ofile<<"$finish;"<<endl;
		ofile<<"end"<<endl;

		//设时钟
		ofile<<"always"<<endl;
		ofile<<"begin : CLOCK_clk"<<endl;
		ofile<<"clk = 1'b0;"<<endl;
		ofile<<"#"<<CLKTIME<<";"<<endl;
		ofile<<"clk = 1'b1;"<<endl;
		ofile<<"#"<<CLKTIME<<";"<<endl;
		ofile<<"end"<<endl;
		ofile<<"endmodule"<<endl;
		ofile.close();
		o=o+1;
	}
}
*/
void constraint_initial()
{
	ConHead = new constraint();
	strcpy(ConHead->c,"");
	strcpy(ConHead->port_name,"");
	strcpy(ConHead->time,"");
	ConHead->next = NULL;
}
bool findport(char* word)
{
	port * p = PortHead;
	while(p->next!=NULL)
	{
		p=p->next;
		if(p->direction==1)
		{
			if(strcmp(p->id,word)==0)
			{
				return true;
			}
		}

	}
	return false;
}
bool mystrstr(char * str1,char * str2)
{
	/*
	//char str[20]="jsdlaadf",substr[10]="sdf";
	char *p=str1,*q=str2;
	int flag=0;
	for(;*(p+strlen(str2)-1);p++)
	{
		for(q=str2;*p==*q&&*q;p++,q++);
			if(!*q)
			{
				flag=1;
				break;
			}
	}	
	if(flag==1) 
		return true;
	else 
		return false;
		*/
		
	//int i=0;
	for(int i=0;i<mystrlen(str1);i++)
	{
		char array[50];
		int k=0;
		while((str1[i]!=',')&&(str1[i]!='\0'))
		{
			
			
			array[k] = str1[i];
			k++;
			i++;

		}
		array[k] = '\0';
		if(strcmp(array,str2)==0)
			return true;
		//i--;
	}
	return false;
}


char * generate_portname(char* c)
{
	char * portname = new char[500];
	strcpy(portname,"");
	int i;
	char array[500];
	char * word;
	int c_length = mystrlen(c);
	for(i=0;i<c_length;i++)
	{
		if((c[i]>='A' && c[i]<='Z') || (c[i]>='a' && c[i]<='z') || (c[i]>='0' && c[i]<='9')||c[i] == '_')
		{
			int k=0;
			while((c[i]>='A' && c[i]<='Z') || (c[i]>='a' && c[i]<='z') || (c[i]>='0' && c[i]<='9')||c[i] == '_')
			{
				array[k++] = c[i++];
			}
			word = new char[k+2];
			memcpy(word,array,k);
			//word[k] = ',';
			word[k] = '\0';
			if(findport(word)&&!mystrstr(portname,word))
			{
				word[k]=',';
				word[k+1]='\0';
				strcat(portname,word);
			}
			i=i-1;
		}
	}
	int l = mystrlen(portname);
	portname[l-1]='\0';
	return portname;
}
/*
char * allinput()
{
	port * po = PortHead;
	char * portname_all;
	strcpy(portname_all,"");
	while(po->next!=NULL)
	{
		po=po->next;
		if(po->direction==1)
		{
			strcat(portname_all,po->id);
			strcat(portname_all,",");
		}
	}
	int l = mystrlen(portname_all);
	portname_all[l-1]="\0";
	return portname_all;
}
*/

	







void create_constraint(char* condition, int pre)//注意：strtok这个函数不能嵌套使用，既如果首先使用了1类型的strtok，然后又换了2类型的strtok，再想换成1类型的strtok是不行的，这里的对condition分#和对mystrstr就是傻逼了
{
	constraint * p=ConHead;
	
	while(p->next!=NULL)
	{
		p=p->next;
	}
	char * condition_temp = new char [mystrlen(condition)+1];
	memcpy(condition_temp,condition,mystrlen(condition));
	condition_temp[mystrlen(condition)]='\0';
	if(pre>0)//有先行
	{
		char * token = strtok(condition_temp,"#");
		if(token!=NULL)
		{
			constraint * temp = new constraint();
			int m=0;
			char array_temp[300];
			if((token[m]>='0')&&(token[m]<='9'))//有先行时分两种情况，一是第一条约束有时序，二是第一条约束没有时序
			{
				while(token[m]!=';')
				{
					array_temp[m]=token[m];
					m++;
				}
				array_temp[m]=';';
				char * word = new char[m+2];
				memcpy(word,array_temp,m+1);
				word[m+1]='\0';
				strcpy(temp->time,"#");
				strcat(temp->time,word);



				int n;
				int i_temp1=m;
				for (n=0;n<mystrlen(token)-i_temp1-1;n++)
				{
					array_temp[n] = token[++m];
				}
				char * word1 = new char [n+1];
				memcpy(word1,array_temp,n);
				word1[n] = '\0';
				strcpy(temp->c,word1);
				strcpy(temp->port_name,generate_portname(word1));
				p->next=temp;
				p=p->next;
			}
			else
			{
				strcpy(temp->c,token);
				strcpy(temp->time,"");
				strcpy(temp->port_name,generate_portname(token));
				p->next=temp;
				p=p->next;
			}
			token = strtok(NULL,"#");
			while(token!=NULL)
			{
				constraint * temp1 = new constraint();
				char  array[300];
				int i=0;
				while(token[i]!=';')
				{
					array[i]=token[i];
					i++;
				}
				array[i] = ';';
				char * word_temp = new char[i+2];
				memcpy(word_temp,array,i+1);
				word_temp[i+1]='\0';
				//temp->time = new char [i+2];
				strcat(temp1->time,"#");
				strcat(temp1->time,word_temp);
				int k;
				int i_temp=i;
				for (k=0;k<mystrlen(token)-i_temp-1;k++)
				{
					array[k] = token[++i];
				}
				char * word = new char [k+1];
				memcpy(word,array,k);
				word[k] = '\0';
				strcpy(temp1->c,word);
				strcpy(temp1->port_name,generate_portname(word));
				p->next=temp1;
				p=p->next;
				token = strtok(NULL,"#");
			}
		}
	}
	else//没有先行的时候一开始不应该有时序的赋值
	{
		char * token = strtok(condition_temp,"#");//出现了错误，strtok不能在一段函数中连续出现
		if(token!=NULL)
		{
			constraint * temp = new constraint();
			strcpy(temp->c,token);
			strcpy(temp->time,"");
			strcpy(temp->port_name,"");
			p->next=temp;
			p=p->next;
			token = strtok(NULL,"#");
			while(token!=NULL)
			{
				constraint * temp1 = new constraint();
				char  array[300];
				int i=0;
				while(token[i]!=';')
				{
					array[i]=token[i];
					i++;
				}
				array[i] = ';';
				char * word_temp = new char[i+2];
				memcpy(word_temp,array,i+1);
				word_temp[i+1]='\0';
				//temp->time = new char [i+2];
				strcat(temp1->time,"#");
				strcat(temp1->time,word_temp);
				int k;
				int i_temp=i; 
				for (k=0;k<mystrlen(token)-i_temp-1;k++)
				{
					array[k] = token[++i];
				}
				
				char * word = new char [k+1];
				memcpy(word,array,k);
				word[k] = '\0';
				strcpy(temp1->c,word);
				strcpy(temp1->port_name,generate_portname(word));
				p->next=temp1;
				p=p->next;
				token = strtok(NULL,"#");
				
			}
		}
	}
}




char * last_action(char * action)
{
	char * action_temp = new char[mystrlen(action)+1];
	memcpy(action_temp,action,mystrlen(action));
	action_temp[mystrlen(action)]='\0';
	char * last_temp = new char [100];
	char* token=strtok(action_temp,";");
	while(token!=NULL)
	{
	strcpy(last_temp,token);
	token=strtok(NULL,";");
	}
	return last_temp;
}


	

void printsv_with_if_class()
{
	function * f = FunHead;
	
	while(f->next!=NULL)
	{	
		int count = 0;
		f=f->next;
		char name[30];
		memcpy(name,f->id,mystrlen(f->id));
		name[mystrlen(f->id)]='\0';
		strcat(name,"_class.sv");
		ofstream ofile;
		ofile.open(name,ios::out);
		ofile<<"class packet"<<count<<";"<<endl;
		port * p;
		p=PortHead;
		while(p->next!=NULL)
		{
			p=p->next;
			if(!(strcmp(p->id,"clk")==0))
			{
				if(p->direction==1)
				{
					if(findconfiguration(f,p))
					{
						ofile<<"randc"<<" "<<"bit"<<" ";
					}
					else
					{
						ofile<<"rand"<<" "<<"bit"<<" ";
					}
					if(p->width>1)
					{
						ofile<<"["<<(p->width-1)<<":"<<"0"<<"]";
					}
					ofile<<p->id<<";"<<endl;
				}
				else
				{
					ofile<<"bit"<<" ";
					if(p->width>1)
					{
						ofile<<"["<<(p->width-1)<<":"<<"0"<<"]";
					}
					ofile<<p->id<<";"<<endl;
				}
			}
		}
		ofile<<"function new(int seed);"<<endl;
		ofile<<"this.srandom(seed);"<<endl;
		ofile<<"endfunction"<<endl;
		if(f->pre==NULL)
		{
			//对约束进行处理，以#进行区别
			constraint_initial();
			create_constraint(f->condition,0);
			//constraint_close();
			constraint * con = ConHead;
			int con_count=0;
			while(con->next!=NULL)
			{
				con=con->next;
				ofile<<"constraint"<<" "<<"c"<<con_count<<"{"<<con->c<<"}"<<endl;
				con_count++;
			}
			ofile<<"endclass"<<endl;
			count++;
		}
		else
		{
			function * f_temp[10];
			int pre_num = 0;
			function * temp = f;
			while(temp->pre!=NULL)
			{
				f_temp[pre_num] = temp;
				pre_num++;
				temp = temp->pre;
			}
			f_temp[pre_num] = temp;
			int con_count=0;
			constraint_initial();
			create_constraint(f_temp[pre_num]->condition,0);
			constraint * con = ConHead;
			while(con->next!=NULL)
			{
				con=con->next;
				ofile<<"constraint"<<" "<<"c"<<con_count<<"{"<<con->c<<"}"<<endl;
				con_count++;
			}
			pre_num--;
			for(int k=pre_num;k>=0;k--)
			{
				constraint_initial();
				create_constraint(f_temp[k]->condition,1);
				con=ConHead;
				while(con->next!=NULL)
				{
					con=con->next;
					ofile<<"constraint"<<" "<<"c"<<con_count<<"{"<<con->c<<"}"<<endl;
					con_count++;
				}
			}
			ofile<<"endclass"<<endl;
			count++;
		}


		//下面是function的边界：

		for(int a=0; a<f->i;a++)
		{
			ofile<<"class packet"<<count<<";"<<endl;
			p=PortHead;
			while(p->next!=NULL)
			{
				p=p->next;
				if(!(strcmp(p->id,"clk")==0))
				{
					if(p->direction==1)
					{
						if(findconfiguration(f,p))
						{
							ofile<<"randc"<<" "<<"bit"<<" ";
						}
						else
						{
							ofile<<"rand"<<" "<<"bit"<<" ";
						}
						if(p->width>1)
						{
							ofile<<"["<<(p->width-1)<<":"<<"0"<<"]";
						}
						ofile<<p->id<<";"<<endl;
					}
					else
					{
						ofile<<"bit"<<" ";
						if(p->width>1)
						{
							ofile<<"["<<(p->width-1)<<":"<<"0"<<"]";
						}
						ofile<<p->id<<";"<<endl;
					}
				}
			}
			if(f->pre==NULL)
			{
				constraint_initial();
				create_constraint(f->boundry_condition[a],0);
				constraint * con = ConHead;
				int con_count=0;
				while(con->next!=NULL)
				{
					con=con->next;
					ofile<<"constraint"<<" "<<"c"<<con_count<<"{"<<con->c<<"}"<<endl;
					con_count++;
				}
				ofile<<"endclass"<<endl;
				count++;
			}
			else
			{
				function * f_temp[10];
				int pre_num = 0;
				function * temp = f;
				while(temp->pre!=NULL)
				{
					f_temp[pre_num] = temp;
					pre_num++;
					temp = temp->pre;
				}
				f_temp[pre_num] = temp;
				int con_count=0;
				constraint_initial();
				create_constraint(f_temp[pre_num]->condition,0);
				constraint * con = ConHead;
				while(con->next!=NULL)
				{
					con=con->next;
					ofile<<"constraint"<<" "<<"c"<<con_count<<"{"<<con->c<<"}"<<endl;
					con_count++;
				}
				pre_num--;
				for(int k=pre_num;k>0;k--)
				{
					constraint_initial();
					create_constraint(f_temp[k]->condition,1);
					con=ConHead;
					while(con->next!=NULL)
					{
						con=con->next;
						ofile<<"constraint"<<" "<<"c"<<con_count<<"{"<<con->c<<"}"<<endl;
						con_count++;
					}	
				}
				constraint_initial();
				create_constraint(f->boundry_condition[a],1);
				con = ConHead;
				while(con->next!=NULL)
				{
					con=con->next;
					ofile<<"constraint"<<" "<<"c"<<con_count<<"{"<<con->c<<"}"<<endl;
					con_count++;
				}
				ofile<<"endclass"<<endl;
				count++;	
			}
		}
			ofile.close();
	}
	

}





			



	
void printsv_with_if_TB()
{
	function * f = FunHead;
	//int o=0;
	while(f->next!=NULL)
	{
		f=f->next;
		char name[30];
		char class_name[30];
		memcpy(name,f->id,mystrlen(f->id));
		name[mystrlen(f->id)]='\0';
		memcpy(class_name,f->id,mystrlen(f->id));
		class_name[mystrlen(f->id)]='\0';
		strcat(name,"_TB.sv");
		strcat(class_name,"_class.sv");
		ofstream ofile;
		ofile.open(name,ios::out);
		ofile<<"`include "<<" \""<<class_name<<"\""<<endl;
		ofile<<"`timescale "<<TIMEUNIT<<" / "<<TIMEPRECISION<<endl;
		ofile<<"module test"<<";"<<endl;
		// port
		port * p = PortHead;
		while(p->next!=NULL)
		{
			p=p->next;
			if(p->direction==1)
			{
				ofile<<"reg"<<"  ";
			}	
			else
			{
				ofile<<"wire"<<"  ";
			}
			if(p->width>1)
			{
				ofile<<"["<<(p->width-1)<<":"<<"0"<<"]";
			}
			ofile<<p->id<<";"<<endl;
		}	
	
		//实例化
		ofile<<"fpu "<<"ins1 "<<"("<<endl;
		p=PortHead;
		while(p->next!=NULL)
		{
			p=p->next;
			if(p->next!=NULL)
			{
				ofile<<"."<<p->id<<"("<<p->id<<")"<<","<<endl;
			}
			else
				ofile<<"."<<p->id<<"("<<p->id<<")"<<endl;
		}
		ofile<<");"<<endl;
		int count=0;
		//int count_all=f->i+1;
		for(int a=0;a<f->i+1;a++)
		{
			ofile<<"packet"<<a<<" "<<" p"<<a<<";"<<endl;
		}

		//开始激励平台赋值主体：
		ofile<<"initial"<<endl;
		ofile<<"begin"<<endl;

		for(int a=0;a<f->i+1;a++)
		{
			ofile<<"p"<<a<<"=new("<<SEED<<");"<<endl;
		}
		ofile<<"#0"<<endl;
		ofile<<RSTSIGNAL<<" = 1'b1;"<<endl;//初始化不一样，这个信号变不一样。
		ofile<<"# "<<RSTTIME<<";"<<endl;//设置的初始化执行时间
		ofile<<"repeat("<<COUNT<<")"<<endl;
		ofile<<"begin"<<endl;
		function * f_temp[10];
		int pre_num = 0;
		function * temp = f;
		while(temp->pre!=NULL)
		{
			f_temp[pre_num] = temp;
			pre_num++;
			temp = temp->pre;
		}
		f_temp[pre_num] = temp;
		constraint * con;
		int con_count=0;
		constraint_initial();
		create_constraint(f_temp[pre_num]->condition,0);
		con = ConHead;
		while(con->next!=NULL)
		{
			con=con->next;
			ofile<<con->time<<endl;
			p=PortHead;
			while(p->next!=NULL)
			{
				p=p->next;
				if(p->direction==2)
				{
					ofile<<"p"<<count<<"."<<p->id<<"="<<p->id<<";"<<endl;
				}
				
			}
			ofile<<"p"<<count<<".constraint_mode(0);"<<endl;
			ofile<<"p"<<count<<".c"<<con_count<<".constraint_mode(1);"<<endl;
			ofile<<"assert(p"<<count<<".randomize("<<con->port_name<<"));"<<endl;
			p=PortHead;
			while(p->next!=NULL)
			{
				p=p->next;
				if(con_count==0)//第一次要把随机值全部打给端口
					{
					if(!(strcmp(p->id,"clk")==0))
					{
						if(p->direction==1)
						{
							ofile<<p->id<<"="<<"p"<<count<<"."<<p->id<<";"<<endl;
						}
					}
				}
				else//后面只需要把更改的打给端口
				{
					if(!(strcmp(p->id,"clk")==0))
					{
						if((p->direction==1)&&mystrstr(con->port_name,p->id))
						{
						ofile<<p->id<<"="<<"p"<<count<<"."<<p->id<<";"<<endl;
						}
				
					}
				}
			}
			con_count++;
		}
		for(int k=pre_num-1;k>=0;k--)
		{
			ofile<<"wait("<<last_action(f_temp[k+1]->action)<<")"<<endl;
			ofile<<"begin"<<endl;
			constraint_initial();
			create_constraint(f_temp[k]->condition,1);
			con = ConHead;
			while(con->next!=NULL)
			{
				con=con->next;
				ofile<<con->time<<endl;
				p=PortHead;
				while(p->next!=NULL)
				{
					p=p->next;
					if(p->direction==2)
					{
						ofile<<"p"<<count<<"."<<p->id<<"="<<p->id<<";"<<endl;
					}
				
				}
				ofile<<"p"<<count<<".constraint_mode(0);"<<endl;
				ofile<<"p"<<count<<".c"<<con_count<<".constraint_mode(1);"<<endl;
				ofile<<"assert(p"<<count<<".randomize("<<con->port_name<<"));"<<endl;
				p=PortHead;
				while(p->next!=NULL)
				{
					p=p->next;
					if(con_count==0)//第一次要把随机值全部打给端口
					{
						if(!(strcmp(p->id,"clk")==0))
						{
							if(p->direction==1)
							{
								ofile<<p->id<<"="<<"p"<<count<<"."<<p->id<<";"<<endl;
							}
						}
					}
					else//后面只需要把更改的打给端口
					{
						if(!(strcmp(p->id,"clk")==0))
						{
							if((p->direction==1)&&mystrstr(con->port_name,p->id))
							{
							ofile<<p->id<<"="<<"p"<<count<<"."<<p->id<<";"<<endl;
							}
					
						}
					}
				}
				con_count++;
			}
		}
		ofile<<"# "<<OPERTIME<<";"<<endl;//功能的延时
		//display所有的信号值
		p=PortHead;
		while(p->next!=NULL)
		{
			p=p->next;
			if(!(strcmp(p->id,"clk")==0))
			{
				ofile<<"$display("<<"\""<<p->id<<"="<<"%b"<<"\""<<","<<p->id<<");"<<endl;
			}
				
		}
		for(int m=0;m<=pre_num;m++)
		{
			ofile<<"end"<<endl;
		}
		count++;//类的数

















/*

		int con_count=0;
		constraint * con;
		int pre_temp=0;//判断当前功能是否有先行功能
		if(f->pre!=NULL)
		{

			pre_temp=1;
			constraint_initial();
			create_constraint(f->pre->condition,0);
			con  = ConHead;
			
			while(con->next!=NULL)
			{
				con=con->next;
				ofile<<con->time<<endl;
				p=PortHead;
				while(p->next!=NULL)
				{
					p=p->next;
					if(p->direction==2)
					{
						ofile<<"p"<<count<<"."<<p->id<<"="<<p->id<<";"<<endl;
					}
				
				}
				ofile<<"p"<<count<<".constraint_mode(0);"<<endl;
				ofile<<"p"<<count<<".c"<<con_count<<".constraint_mode(1);"<<endl;
				ofile<<"assert(p"<<count<<".randomize("<<con->port_name<<"));"<<endl;
				p=PortHead;
				while(p->next!=NULL)
				{
					p=p->next;
					if(con_count==0)//第一次要把随机值全部打给端口
					{
						if(!(strcmp(p->id,"clk")==0))
						{
							if(p->direction==1)
							{
								ofile<<p->id<<"="<<"p"<<count<<"."<<p->id<<";"<<endl;
							}
						}
					}
					else//后面只需要把更改的打给端口
					{
						if(!(strcmp(p->id,"clk")==0))
						{
							if((p->direction==1)&&mystrstr(con->port_name,p->id))
							{
							ofile<<p->id<<"="<<"p"<<count<<"."<<p->id<<";"<<endl;
							}
					
						}
					}
				}
				con_count++;
			}
			ofile<<"wait("<<last_action(f->pre->action)<<")"<<endl;
			ofile<<"begin"<<endl;
			
		}
		constraint_initial();
		create_constraint(f->condition,pre_temp);
		con = ConHead;
		//int con_count=0;
		while(con->next!=NULL)
		{
			con=con->next;
			ofile<<con->time<<endl;
			p=PortHead;
			while(p->next!=NULL)
			{
				p=p->next;
				if(p->direction==2)
				{
					ofile<<"p"<<count<<"."<<p->id<<"="<<p->id<<";"<<endl;
				}
				
			}

			ofile<<"p"<<count<<".constraint_mode(0);"<<endl;
			ofile<<"p"<<count<<".c"<<con_count<<".constraint_mode(1);"<<endl;
			ofile<<"assert(p"<<count<<".randomize("<<con->port_name<<"));"<<endl;
			p=PortHead;
			while(p->next!=NULL)
			{
				p=p->next;
				if(con_count==0)//第一次要把随机值全部打给端口
				{
					if(!(strcmp(p->id,"clk")==0))
					{
						if(p->direction==1)
						{
							ofile<<p->id<<"="<<"p"<<count<<"."<<p->id<<";"<<endl;
						}
					}
				}
				else//后面只需要把更改的打给端口
				{
					if(!(strcmp(p->id,"clk")==0))
					{
						if((p->direction==1)&&mystrstr(con->port_name,p->id))
						{
							ofile<<p->id<<"="<<"p"<<count<<"."<<p->id<<";"<<endl;
						}
					
					}
				}
			}
			con_count++;
		}
		ofile<<"# "<<OPERTIME<<";"<<endl;//功能的延时
		//display所有的信号值
		p=PortHead;
		while(p->next!=NULL)
		{
			p=p->next;
			if(!(strcmp(p->id,"clk")==0))
			{
				ofile<<"$display("<<"\""<<p->id<<"="<<"%b"<<"\""<<","<<p->id<<");"<<endl;
			}
				
		}
		if(f->pre!=NULL)
		{
			ofile<<"end"<<endl;
		}
		ofile<<"end"<<endl;	
		count++;
*/
	













		for(int a=0;a<f->i;a++)
		{
			//ofile<<"packet"<<count<<" "<<" p"<<count<<";"<<endl;
			//ofile<<"p"<<count<<"=new();"<<endl;
			//不给初始化了这里
			/*
			ofile<<"#0"<<endl;
			ofile<<RSTSIGNAL<<" = 1'b1;"<<endl;//初始化不一样，这个信号变不一样。
			ofile<<"# "<<RSTTIME<<";"<<endl;//设置的初始化执行时间
			*/

			ofile<<"repeat("<<COUNT<<")"<<endl;
			ofile<<"begin"<<endl;
			con_count=0;
			if(pre_num==0)
			{
				constraint_initial();
				create_constraint(f->boundry_condition[a],0);
				con = ConHead;
				while(con->next!=NULL)
				{
					con=con->next;
					ofile<<con->time<<endl;
					p=PortHead;
					while(p->next!=NULL)
					{
						p=p->next;
						if(p->direction==2)
						{
						ofile<<"p"<<count<<"."<<p->id<<"="<<p->id<<";"<<endl;
						}
				
					}
					ofile<<"p"<<count<<".constraint_mode(0);"<<endl;
					ofile<<"p"<<count<<".c"<<con_count<<".constraint_mode(1);"<<endl;
					ofile<<"assert(p"<<count<<".randomize("<<con->port_name<<"));"<<endl;
					p=PortHead;
					while(p->next!=NULL)
					{
						p=p->next;
						if(con_count==0)//第一次要把随机值全部打给端口
						{
							if(!(strcmp(p->id,"clk")==0))
							{
								if(p->direction==1)
								{
									ofile<<p->id<<"="<<"p"<<count<<"."<<p->id<<";"<<endl;
								}
							}
						}
						else//后面只需要把更改的打给端口
						{
							if(!(strcmp(p->id,"clk")==0))
							{
								if((p->direction==1)&&mystrstr(con->port_name,p->id))
								{
								ofile<<p->id<<"="<<"p"<<count<<"."<<p->id<<";"<<endl;
								}
				
							}
						}
					}
					con_count++;
				}
			}
			else
			{
				constraint_initial();
				create_constraint(f_temp[pre_num]->condition,0);
				con = ConHead;
				while(con->next!=NULL)
				{
					con=con->next;
					ofile<<con->time<<endl;
					p=PortHead;
					while(p->next!=NULL)
					{
						p=p->next;
						if(p->direction==2)
						{
							ofile<<"p"<<count<<"."<<p->id<<"="<<p->id<<";"<<endl;
						}
				
					}
					ofile<<"p"<<count<<".constraint_mode(0);"<<endl;
					ofile<<"p"<<count<<".c"<<con_count<<".constraint_mode(1);"<<endl;
					ofile<<"assert(p"<<count<<".randomize("<<con->port_name<<"));"<<endl;
					p=PortHead;
					while(p->next!=NULL)
					{
						p=p->next;
						if(con_count==0)//第一次要把随机值全部打给端口
						{
							if(!(strcmp(p->id,"clk")==0))
							{
								if(p->direction==1)
								{
									ofile<<p->id<<"="<<"p"<<count<<"."<<p->id<<";"<<endl;
								}
							}
						}
						else//后面只需要把更改的打给端口
						{
							if(!(strcmp(p->id,"clk")==0))
							{
								if((p->direction==1)&&mystrstr(con->port_name,p->id))
								{
								ofile<<p->id<<"="<<"p"<<count<<"."<<p->id<<";"<<endl;
								}
				
							}
						}
					}
					con_count++;
				}
				for(int k=pre_num-1;k>0;k--)
				{
					ofile<<"wait("<<last_action(f_temp[k+1]->action)<<")"<<endl;
					ofile<<"begin"<<endl;
					constraint_initial();
					create_constraint(f_temp[k]->condition,1);
					con = ConHead;
					while(con->next!=NULL)
					{
						con=con->next;
						ofile<<con->time<<endl;
						p=PortHead;
						while(p->next!=NULL)
						{
							p=p->next;
							if(p->direction==2)
							{
								ofile<<"p"<<count<<"."<<p->id<<"="<<p->id<<";"<<endl;
							}
				
						}
						ofile<<"p"<<count<<".constraint_mode(0);"<<endl;
						ofile<<"p"<<count<<".c"<<con_count<<".constraint_mode(1);"<<endl;
						ofile<<"assert(p"<<count<<".randomize("<<con->port_name<<"));"<<endl;
						p=PortHead;
						while(p->next!=NULL)
						{
							p=p->next;
							if(con_count==0)//第一次要把随机值全部打给端口
							{
								if(!(strcmp(p->id,"clk")==0))
								{
									if(p->direction==1)
									{
										ofile<<p->id<<"="<<"p"<<count<<"."<<p->id<<";"<<endl;
									}
								}
							}
							else//后面只需要把更改的打给端口
							{
								if(!(strcmp(p->id,"clk")==0))
								{
									if((p->direction==1)&&mystrstr(con->port_name,p->id))
									{
									ofile<<p->id<<"="<<"p"<<count<<"."<<p->id<<";"<<endl;
									}
					
								}
							}	
						}
						con_count++;
					}
				}
				constraint_initial();
				create_constraint(f->boundry_condition[a],1);
				con = ConHead;
				while(con->next!=NULL)
				{
					con=con->next;
					ofile<<con->time<<endl;
					p=PortHead;
					while(p->next!=NULL)
					{
						p=p->next;
						if(p->direction==2)
						{
						ofile<<"p"<<count<<"."<<p->id<<"="<<p->id<<";"<<endl;
						}
				
					}
					ofile<<"p"<<count<<".constraint_mode(0);"<<endl;
					ofile<<"p"<<count<<".c"<<con_count<<".constraint_mode(1);"<<endl;
					ofile<<"assert(p"<<count<<".randomize("<<con->port_name<<"));"<<endl;
					p=PortHead;
					while(p->next!=NULL)
					{
						p=p->next;
						if(con_count==0)//第一次要把随机值全部打给端口
						{
							if(!(strcmp(p->id,"clk")==0))
							{
								if(p->direction==1)
								{
									ofile<<p->id<<"="<<"p"<<count<<"."<<p->id<<";"<<endl;
								}
							}
						}
						else//后面只需要把更改的打给端口
						{
							if(!(strcmp(p->id,"clk")==0))
							{
								if((p->direction==1)&&mystrstr(con->port_name,p->id))
								{
								ofile<<p->id<<"="<<"p"<<count<<"."<<p->id<<";"<<endl;
								}
				
							}
						}
					}
					con_count++;
				}
			}
			ofile<<"# "<<OPERTIME<<";"<<endl;//功能的延时
			//display所有的信号值
			p=PortHead;
			while(p->next!=NULL)
			{
				p=p->next;
			if(!(strcmp(p->id,"clk")==0))
				{
					ofile<<"$display("<<"\""<<p->id<<"="<<"%b"<<"\""<<","<<p->id<<");"<<endl;
				}
				
			}
			for(int m=0;m<=pre_num;m++)
			{
				ofile<<"end"<<endl;
			}
			count++;//类的数
		}


/*

			if(f->pre!=NULL)
			{
				constraint_initial();
				create_constraint(f->pre->condition,0);
				constraint * con = ConHead;
				while(con->next!=NULL)
				{
					con=con->next;
					ofile<<con->time<<endl;
					p=PortHead;
					while(p->next!=NULL)
					{
						p=p->next;
						if(p->direction==2)
						{
							ofile<<"p"<<count<<"."<<p->id<<"="<<p->id<<";"<<endl;
						}
				
					}
					ofile<<"p"<<count<<".constraint_mode(0);"<<endl;
					ofile<<"p"<<count<<".c"<<con_count<<".constraint_mode(1);"<<endl;
					ofile<<"assert(p"<<count<<".randomize("<<con->port_name<<"));"<<endl;
					p=PortHead;
					while(p->next!=NULL)
					{
						p=p->next;
						if(con_count==0)//第一次要把随机值全部打给端口
						{
							if(!(strcmp(p->id,"clk")==0))
							{
								if(p->direction==1)
								{
									ofile<<p->id<<"="<<"p"<<count<<"."<<p->id<<";"<<endl;
								}
							}
						}
						else//后面只需要把更改的打给端口
						{
							if(!(strcmp(p->id,"clk")==0))
							{
								if((p->direction==1)&&mystrstr(con->port_name,p->id))
								{
								ofile<<p->id<<"="<<"p"<<count<<"."<<p->id<<";"<<endl;
								}
					
							}
						}
					}
					con_count++;
				}
				ofile<<"wait("<<last_action(f->pre->action)<<")"<<endl;
				ofile<<"begin"<<endl;
			}
			constraint_initial();
			create_constraint(f->boundry_condition[a],pre_temp);
			constraint * con = ConHead;
			
			while(con->next!=NULL)
			{
				con=con->next;
				ofile<<con->time<<endl;
				p=PortHead;
				while(p->next!=NULL)
				{
					p=p->next;
					if(p->direction==2)
					{
						ofile<<"p"<<count<<"."<<p->id<<"="<<p->id<<";"<<endl;
					}
				
				}
				ofile<<"p"<<count<<".constraint_mode(0);"<<endl;
				ofile<<"p"<<count<<".c"<<con_count<<".constraint_mode(1);"<<endl;
				ofile<<"assert(p"<<count<<".randomize("<<con->port_name<<"));"<<endl;
				
				p=PortHead;
				while(p->next!=NULL)
				{
					p=p->next;
					if(con_count==0)
					{
						if(!(strcmp(p->id,"clk")==0))
						{
							if(p->direction==1)
							{
								ofile<<p->id<<"="<<"p"<<count<<"."<<p->id<<";"<<endl;
							}
						}
					}
					else
					{
						if(!(strcmp(p->id,"clk")==0))
						{
							if((p->direction==1)&&mystrstr(con->port_name,p->id))
							{
								ofile<<p->id<<"="<<"p"<<count<<"."<<p->id<<";"<<endl;
							}
					
						}
					}
				}
				con_count++;
			}
			ofile<<"# "<<OPERTIME<<";"<<endl;//功能的延时
			//display所有的信号值
			p=PortHead;
			while(p->next!=NULL)
			{
				p=p->next;
				if(!(strcmp(p->id,"clk")==0))
				{
					ofile<<"$display("<<"\""<<p->id<<"="<<"%b"<<"\""<<","<<p->id<<");"<<endl;
				}
				
			}
			if(f->pre!=NULL)
			{
				ofile<<"end"<<endl;
			}
				
			ofile<<"end"<<endl;	
			count++;
		}
*/
		ofile<<"$finish;"<<endl;
		ofile<<"end"<<endl;
		//设时钟
		ofile<<"always"<<endl;
		ofile<<"begin : CLOCK_clk"<<endl;
		ofile<<"clk = 1'b0;"<<endl;
		ofile<<"#"<<CLKTIME<<";"<<endl;
		ofile<<"clk = 1'b1;"<<endl;
		ofile<<"#"<<CLKTIME<<";"<<endl;
		ofile<<"end"<<endl;
		ofile<<"endmodule"<<endl;
		ofile.close();
	}
}


		


	

		










