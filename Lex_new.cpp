//LexAnalysis.cpp

#include "LexAnalysis.h"

using namespace std;

port * PortHead;//端口首结点
transaction * TranHead;
function* FunHead;
boundry_condition * BounHead;
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
	/*
	for(int i=0;i<10;i++)
	{
		strcpy(FunHead->boundry_condition[i],"");
	}
	*/
	
	FunHead->next=NULL;
	BounHead = new boundry_condition();
	BounHead->f=NULL;
	for(int i=0;i<10;i++)
	{
		strcpy(BounHead->condition[i],"");
	}
	BounHead->i=-1;
	BounHead->next=NULL;




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

void createfunction(char* id, char* condition, char* action, char* configuration)
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
	p->next=temp;
	
}     
            
void  printfunction()
{
	function * p=FunHead;
	while(p->next!=NULL)
	{
		p=p->next;
		cout<<p->id<<endl<<p->condition<<endl<<p->configuration<<endl<<p->action<<endl;

	}
	int i;
	cin>>i;
}
function * fathersearch(char * id)
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
char * unfoldcondition(char* condition)
{
		char * constraint = new char[500];
		strcpy(constraint,"");
		int i;
		char array[500];
		char * word;
		int condition_length = mystrlen(condition);
//		char* c = condition;
		for(i=0;i<condition_length;i++)
		{
			if((condition[i]>='A' && condition[i]<='Z') || (condition[i]>='a' && condition[i]<='z') || condition[i] == '_')//事务的名字不支持出现数字,这一段是将调用的事务展开的
			{
				int k=0;
				//array="";
				while((condition[i]>='A' && condition[i]<='Z') || (condition[i]>='a' && condition[i]<='z') || condition[i] == '_')
				{
					array[k++] = condition[i++];
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
				word[0]=condition[i];
				word[1]='\0';
				strcat(constraint,word);
			}
		}
		return constraint;
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
						
						

					createfunction(id,unfoldcondition(condition),action,configuration);

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
						if(fathersearch(fatherid)==NULL)
						{
							errorfunction(line);
							break;
						}
						else
						{
							condition = new char [500];
							action = new char [500];
							configuration = new char[100];
							function * father = fathersearch(fatherid);
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
							createfunction(id,unfoldcondition(condition),action,configuration);
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

	



