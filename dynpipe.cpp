#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <cerrno>
#include <sstream>
#include <string>
#include <sys/wait.h>


using namespace std;

int main(int argc, char **argv)
{
	int status = 0;
	int i = argc - 1;
	int pipe1[2];
	int pipe2[2];
	int pipe3[2];
	int pipe4[2];
	char *arg1[] = {"", "", NULL};
	char *arg2[] = {"", "", NULL};
	char *arg3[] = {"", "", NULL};
	char *arg4[] = {"", "", NULL};
	char *arg5[] = {"", "", NULL};
	pid_t pid1, pid2, pid3, pid4, pid5, wpid;
	if (i < 2 || i > 5)
	{
	errno = EINVAL;
	if (i < 2) perror("Insufficient arugments provided");
	else perror("Too many arguments provided");
	return(1);
	}
	if (i == 2){
	pipe(pipe1);
	if ((pid1 = fork()) < 0)
	{
	perror("Error creating 1st child");
	exit(1);
	}
	else if (pid1 == 0)
	{	
	stringstream ss;
	ss << argv[2];
	string x;
	string y;
	ss >> x;
	ss >> y;
	arg2[0] = (char*) x.c_str();
	arg2[1] = (char*) y.c_str();	
	dup2(pipe1[0], 0);
	close(pipe1[0]);
	close(pipe1[1]);
	execvp(*arg2, arg2);
	}
	if ((pid2 = fork()) < 0)
	{
	perror("Error creating 2nd child");
	exit(1);
	}
	else if (pid2 == 0)
	{	
	stringstream ss;
	ss << argv[1];
	string x;
	string y;
	ss >> x;
	ss >> y;
	arg1[0] = (char*) x.c_str();
	arg1[1] = (char*) y.c_str();	
	dup2(pipe1[1], 1);
	close(pipe1[0]);
	close(pipe1[1]);
	execvp(*arg1, arg1);	
	}
	}
	if (i == 3)
	{
	pipe(pipe1);
	pipe(pipe2);
	if ((pid1 = fork()) < 0)
	{
	perror("Error creating 1st child");
	exit(1);
	}
	else if (pid1 == 0)
	{	
	stringstream ss;
	ss << argv[3];
	string x;
	string y;
	ss >> x;
	ss >> y;
	arg3[0] = (char*) x.c_str();
	arg3[1] = (char*) y.c_str();	
	dup2(pipe2[0], 0);
	close(pipe1[0]);
	close(pipe1[1]);
	close(pipe2[0]);
	close(pipe2[1]);
	execvp(*arg3, arg3);
	}
	if ((pid2 = fork()) < 0)
	{
	perror("Error creating 2nd child");
	exit(1);
	}
	else if (pid2 == 0)
	{	
	stringstream ss;
	ss << argv[2];
	string x;
	string y;
	ss >> x;
	ss >> y;
	arg2[0] = (char*) x.c_str();
	arg2[1] = (char*) y.c_str();	
	dup2(pipe1[0], 0);
	dup2(pipe2[1], 1);
	close(pipe1[0]);
	close(pipe1[1]);
	close(pipe2[0]);
	close(pipe2[1]);
	execvp(*arg2, arg2);	
	}
	if ((pid3 = fork()) < 0)
	{
	perror("Error creating 3rd child");
	exit(1);
	}
	else if (pid3 == 0)
	{	
	stringstream ss;
	ss << argv[1];
	string x;
	string y;
	ss >> x;
	ss >> y;
	arg1[0] = (char*) x.c_str();
	arg1[1] = (char*) y.c_str();	
	dup2(pipe1[1], 1);
	close(pipe1[0]);
	close(pipe1[1]);
	close(pipe2[0]);
	close(pipe2[1]);
	execvp(*arg1, arg1);	
	}
	} 
	if (i == 4)
	{
	pipe(pipe1);
	pipe(pipe2);
	pipe(pipe3);
	if ((pid1 = fork()) < 0)
	{
	perror("Error creating 1st child");
	exit(1);
	}
	else if (pid1 == 0)
	{
	stringstream ss;
	ss << argv[4];
	string x;
	string y;
	ss >> x;
	ss >> y;
	arg4[0] = (char*) x.c_str();
	arg4[1] = (char*) y.c_str();	
	dup2(pipe3[0], 0);
	close(pipe1[0]);
	close(pipe1[1]);
	close(pipe2[0]);
	close(pipe2[1]);
	close(pipe3[0]);
	close(pipe3[1]);
	execvp(*arg4, arg4);			
	}
	if ((pid2 = fork()) < 0)
	{
	perror("Error creating 2nd child");
	exit(1);
	}
	else if (pid2 == 0)
	{	
	stringstream ss;
	ss << argv[3];
	string x;
	string y;
	ss >> x;
	ss >> y;
	arg3[0] = (char*) x.c_str();
	arg3[1] = (char*) y.c_str();	
	dup2(pipe2[0], 0);
	dup2(pipe3[1], 1);
	close(pipe1[0]);
	close(pipe1[1]);
	close(pipe2[0]);
	close(pipe2[1]);
	close(pipe3[0]);
	close(pipe3[1]);
	execvp(*arg3, arg3);
	}
	if ((pid3 = fork()) < 0)
	{
	perror("Error creating 3rd child");
	exit(1);
	}
	else if (pid3 == 0)
	{	
	stringstream ss;
	ss << argv[2];
	string x;
	string y;
	ss >> x;
	ss >> y;
	arg2[0] = (char*) x.c_str();
	arg2[1] = (char*) y.c_str();	
	dup2(pipe1[0], 0);
	dup2(pipe2[1], 1);
	close(pipe1[0]);
	close(pipe1[1]);
	close(pipe2[0]);
	close(pipe2[1]);
	close(pipe3[0]);
	close(pipe3[1]);
	execvp(*arg2, arg2);	
	}
	if ((pid4 = fork()) < 0)
	{
				perror("Error creating 4th child");
							exit(1);
									}
											else if (pid4 == 0)
													{	
																
																			stringstream ss;
																						ss << argv[1];
																									string x;
																												string y;
																															ss >> x;
																																		ss >> y;
																																					arg1[0] = (char*) x.c_str();
																																								arg1[1] = (char*) y.c_str();	
																																											
																																														dup2(pipe1[1], 1);
																																																	
																																																				close(pipe1[0]);
																																																							close(pipe1[1]);
																																																										close(pipe2[0]);
																																																													close(pipe2[1]);
																																																																close(pipe3[0]);
																																																																			close(pipe3[1]);
																																																																						execvp(*arg1, arg1);	
																																																																								}
																																																																									}
																																																																										if (i == 5)
																																																																											{
																																																																													pipe(pipe1);
																																																																															pipe(pipe2);
																																																																																	pipe(pipe3);
																																																																																			pipe(pipe4);
																																																																																					if ((pid1 = fork()) < 0)
																																																																																							{
																																																																																										perror("Error creating 1st child");
																																																																																													exit(1);
																																																																																															}
																																																																																																	else if (pid1 == 0)
																																																																																																			{
																																																																																																						
																																																																																																									stringstream ss;
																																																																																																												ss << argv[5];
																																																																																																															string x;
																																																																																																																		string y;
																																																																																																																					ss >> x;
																																																																																																																								ss >> y;
																																																																																																																											arg5[0] = (char*) x.c_str();
																																																																																																																														arg5[1] = (char*) y.c_str();	
																																																																																																																																	
																																																																																																																																				dup2(pipe4[0], 0);
																																																																																																																																							
																																																																																																																																										close(pipe1[0]);
																																																																																																																																													close(pipe1[1]);
																																																																																																																																																close(pipe2[0]);
																																																																																																																																																			close(pipe2[1]);
																																																																																																																																																						close(pipe3[0]);
																																																																																																																																																									close(pipe3[1]);
																																																																																																																																																												close(pipe4[0]);
																																																																																																																																																															close(pipe4[1]);
																																																																																																																																																																		execvp(*arg5, arg5);			
																																																																																																																																																																				}
																																																																																																																																																																						if ((pid2 = fork()) < 0)
																																																																																																																																																																								{
																																																																																																																																																																											perror("Error creating 2nd child");
																																																																																																																																																																														exit(1);
																																																																																																																																																																																}
																																																																																																																																																																																		else if (pid2 == 0)
																																																																																																																																																																																				{	
																																																																																																																																																																																							
																																																																																																																																																																																										stringstream ss;
																																																																																																																																																																																													ss << argv[4];
																																																																																																																																																																																																string x;
																																																																																																																																																																																																			string y;
																																																																																																																																																																																																						ss >> x;
																																																																																																																																																																																																									ss >> y;
																																																																																																																																																																																																												arg4[0] = (char*) x.c_str();
																																																																																																																																																																																																															arg4[1] = (char*) y.c_str();	
																																																																																																																																																																																																																		
																																																																																																																																																																																																																					dup2(pipe3[0], 0);
																																																																																																																																																																																																																								dup2(pipe4[1], 1);
																																																																																																																																																																																																																											
																																																																																																																																																																																																																														close(pipe1[0]);
																																																																																																																																																																																																																																	close(pipe1[1]);
																																																																																																																																																																																																																																				close(pipe2[0]);
																																																																																																																																																																																																																																							close(pipe2[1]);
																																																																																																																																																																																																																																										close(pipe3[0]);
																																																																																																																																																																																																																																													close(pipe3[1]);
																																																																																																																																																																																																																																																close(pipe4[0]);
																																																																																																																																																																																																																																																			close(pipe4[1]);
																																																																																																																																																																																																																																																						execvp(*arg4, arg4);
																																																																																																																																																																																																																																																								}
																																																																																																																																																																																																																																																										if ((pid3 = fork()) < 0)
																																																																																																																																																																																																																																																												{
																																																																																																																																																																																																																																																															perror("Error creating 3rd child");
																																																																																																																																																																																																																																																																		exit(1);
																																																																																																																																																																																																																																																																				}
																																																																																																																																																																																																																																																																						else if (pid3 == 0)
																																																																																																																																																																																																																																																																								{	
																																																																																																																																																																																																																																																																											
																																																																																																																																																																																																																																																																														stringstream ss;
																																																																																																																																																																																																																																																																																	ss << argv[3];
																																																																																																																																																																																																																																																																																				string x;
																																																																																																																																																																																																																																																																																							string y;
																																																																																																																																																																																																																																																																																										ss >> x;
																																																																																																																																																																																																																																																																																													ss >> y;
																																																																																																																																																																																																																																																																																																arg3[0] = (char*) x.c_str();
																																																																																																																																																																																																																																																																																																			arg3[1] = (char*) y.c_str();	
																																																																																																																																																																																																																																																																																																						
																																																																																																																																																																																																																																																																																																									dup2(pipe2[0], 0);
																																																																																																																																																																																																																																																																																																												dup2(pipe3[1], 1);
																																																																																																																																																																																																																																																																																																															
																																																																																																																																																																																																																																																																																																																		close(pipe1[0]);
																																																																																																																																																																																																																																																																																																																					close(pipe1[1]);
																																																																																																																																																																																																																																																																																																																								close(pipe2[0]);
																																																																																																																																																																																																																																																																																																																											close(pipe2[1]);
																																																																																																																																																																																																																																																																																																																														close(pipe3[0]);
																																																																																																																																																																																																																																																																																																																																	close(pipe3[1]);
																																																																																																																																																																																																																																																																																																																																				close(pipe4[0]);
																																																																																																																																																																																																																																																																																																																																							close(pipe4[1]);
																																																																																																																																																																																																																																																																																																																																										execvp(*arg3, arg3);	
																																																																																																																																																																																																																																																																																																																																												}
																																																																																																																																																																																																																																																																																																																																														if ((pid4 = fork()) < 0)
																																																																																																																																																																																																																																																																																																																																																{
																																																																																																																																																																																																																																																																																																																																																			perror("Error creating 4th child");
																																																																																																																																																																																																																																																																																																																																																						exit(1);
																																																																																																																																																																																																																																																																																																																																																								}
																																																																																																																																																																																																																																																																																																																																																										else if (pid4 == 0)
																																																																																																																																																																																																																																																																																																																																																												{	
																																																																																																																																																																																																																																																																																																																																																															
																																																																																																																																																																																																																																																																																																																																																																		stringstream ss;
																																																																																																																																																																																																																																																																																																																																																																					ss << argv[2];
																																																																																																																																																																																																																																																																																																																																																																								string x;
																																																																																																																																																																																																																																																																																																																																																																											string y;
																																																																																																																																																																																																																																																																																																																																																																														ss >> x;
																																																																																																																																																																																																																																																																																																																																																																																	ss >> y;
																																																																																																																																																																																																																																																																																																																																																																																				arg2[0] = (char*) x.c_str();
																																																																																																																																																																																																																																																																																																																																																																																							arg2[1] = (char*) y.c_str();	
																																																																																																																																																																																																																																																																																																																																																																																										
																																																																																																																																																																																																																																																																																																																																																																																													dup2(pipe1[0], 0);
																																																																																																																																																																																																																																																																																																																																																																																																dup2(pipe2[1], 1);
																																																																																																																																																																																																																																																																																																																																																																																																			
																																																																																																																																																																																																																																																																																																																																																																																																						close(pipe1[0]);
																																																																																																																																																																																																																																																																																																																																																																																																									close(pipe1[1]);
																																																																																																																																																																																																																																																																																																																																																																																																												close(pipe2[0]);
																																																																																																																																																																																																																																																																																																																																																																																																															close(pipe2[1]);
																																																																																																																																																																																																																																																																																																																																																																																																																		close(pipe3[0]);
																																																																																																																																																																																																																																																																																																																																																																																																																					close(pipe3[1]);
																																																																																																																																																																																																																																																																																																																																																																																																																								close(pipe4[0]);
																																																																																																																																																																																																																																																																																																																																																																																																																											close(pipe4[1]);
																																																																																																																																																																																																																																																																																																																																																																																																																														execvp(*arg2, arg2);	
																																																																																																																																																																																																																																																																																																																																																																																																																																}
																																																																																																																																																																																																																																																																																																																																																																																																																																		if ((pid5 = fork()) < 0)
																																																																																																																																																																																																																																																																																																																																																																																																																																				{
																																																																																																																																																																																																																																																																																																																																																																																																																																							perror("Error creating 5th child");
																																																																																																																																																																																																																																																																																																																																																																																																																																										exit(1);
																																																																																																																																																																																																																																																																																																																																																																																																																																												}
																																																																																																																																																																																																																																																																																																																																																																																																																																														else if (pid5 == 0)
																																																																																																																																																																																																																																																																																																																																																																																																																																																{	
																																																																																																																																																																																																																																																																																																																																																																																																																																																			
																																																																																																																																																																																																																																																																																																																																																																																																																																																						stringstream ss;
																																																																																																																																																																																																																																																																																																																																																																																																																																																									ss << argv[1];
																																																																																																																																																																																																																																																																																																																																																																																																																																																												string x;
																																																																																																																																																																																																																																																																																																																																																																																																																																																															string y;
																																																																																																																																																																																																																																																																																																																																																																																																																																																																		ss >> x;
																																																																																																																																																																																																																																																																																																																																																																																																																																																																					ss >> y;
																																																																																																																																																																																																																																																																																																																																																																																																																																																																								arg1[0] = (char*) x.c_str();
																																																																																																																																																																																																																																																																																																																																																																																																																																																																											arg1[1] = (char*) y.c_str();	
																																																																																																																																																																																																																																																																																																																																																																																																																																																																														
																																																																																																																																																																																																																																																																																																																																																																																																																																																																																	dup2(pipe1[1], 1);
																																																																																																																																																																																																																																																																																																																																																																																																																																																																																				
																																																																																																																																																																																																																																																																																																																																																																																																																																																																																							close(pipe1[0]);
																																																																																																																																																																																																																																																																																																																																																																																																																																																																																										close(pipe1[1]);
																																																																																																																																																																																																																																																																																																																																																																																																																																																																																													close(pipe2[0]);
																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																close(pipe2[1]);
																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																			close(pipe3[0]);
																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																						close(pipe3[1]);
																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																									close(pipe4[0]);
																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																												close(pipe4[1]);
																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																															execvp(*arg1, arg1);	
																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																	}
																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																		}	
																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																			
																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																				close(pipe1[0]);
																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																					close(pipe1[1]);
																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																						close(pipe2[0]);
																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																							close(pipe2[1]);
																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																								close(pipe3[0]);
																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																									close(pipe3[1]);
																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																										close(pipe4[0]);
																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																											close(pipe4[1]);
																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																												while((wpid = wait(&status)) > 0);
																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																												return(0);
																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																																												}

