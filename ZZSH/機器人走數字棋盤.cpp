#include<stdio.h>

using namespace std;

//�D��:����J��ƪ�ܰ}�C�j�p
//     ���ۿ�J�}�C(�|�Ů� ����)(���ӬO���|�����ƪ��Ʀr) 
//     �����H�N�q�Ʀr�̤p���ư_�B
//     ���V�۾F�|�椤�̤p����
//     ���L����N���A��
//     �`:�Ʀr�N�����j��100000���D�t��� 
//                                �D:����L���i���� ���~�����Ʀr�ۥ[ 
int main()
{
	int A,B;
	printf("����J��ƪ�ܰ}�C�j�p (�n�Ů�) ex:2 2\n\n���ۿ�J�}�C (�n�Ů� ����)\n\n�����H�N�q�Ʀr�̤p���ư_�B\n\n���V�۾F�|�椤�̤p����\n\n���L����N���A��\n\n���ܵ����ÿ�X�`�M\n\n�ж}�l��J:");
	while(scanf("%d %d",&A,&B)!=EOF)
	{
		int E[A][B];
		for(int i=0;i<A;i++)
		{
			for(int j=0;j<B;j++)
			{
				scanf("%d",&E[i][j]);
			}
		}
		printf("\n�}�C��:\n");
		for(int i=0;i<A;i++)
		{
			for(int j=0;j<B;j++)
			{
				printf("%d ",E[i][j]);
				if(j==(B-1))
				{
					printf("\n");
				}
			}
		}
		//-------------------------------------------------�}�C��J���� 
		int M,N,m,n;
		m=0;
		n=0;
		for(int i=0;i<A;i++)
		{
			for(int j=0;j<B;j++)
			{
				if(E[i][j]<E[m][n])
				{
					m=i;
					n=j;
				}
			}
		}
		printf("\n�̤p�Ʀr(�_�I)��:%d\n",E[m][n]);
		M=m;
		N=n;
		//--------------------------------------------------find min----end
		int Count=0,Sum=0;
		int D=0;
		D=E[m][n];
		Sum=D;
		E[m][n]=100001;
		while(Count!=4)
		{
			m=M;
			n=N;
			Count=0;
			//��    �W �U �� �k     �j�d 
			for(int i=1;i<=4;i++)
		    {
			    // 1
			    if(i==1)
			    {
				    if(((m-1)>=0)&&(E[m-1][n]<100001))
				    {
				    	M=m-1;
				    	N=n;
					}
					else
					{
						Count=Count+1;
					}
			    }
			    // 2
			    if(i==2)
			    {
				    if(((m+1)<A)&&(E[m+1][n]<100001))
				    {
				    	if(Count==1)
				    	{
				    		M=m+1;
							N=n;
						}
						else if(E[m+1][n]<E[M][N])
						{
							M=m+1;
							N=n;
						}
						else
						{
							Count=Count+1;
						}
					}
					else
					{
						Count=Count+1;
					}
			    }
			    // 3
			    if(i==3)
			    {
				    if(((n-1)>=0)&&(E[m][n-1]<100001))
				    {
				    	if(Count==2)
				    	{
				    		M=m;
							N=n-1;
						}
						else if(E[m][n-1]<E[M][N])
						{
							M=m;
							N=n-1;
						}
						else
						{
							Count=Count+1;
						}
					}
					else
					{
						Count=Count+1;
					}
			    }
			    // 4
			    if(i==4)
			    {
			    	if(((n+1)<B)&&(E[m][n+1]<100001))
				    {
				    	if(Count==3)
				    	{
				    		M=m;
							N=n+1;
						}
						else if(E[m][n+1]<E[M][N])
						{
							M=m;
							N=n+1;
						}
						else
						{
							Count=Count+1;
						}
					}
					else
					{
						Count=Count+1;
					}
			    }
		    }
		    //----------------find
		    if(Count!=4)
		    {
		    	printf(">>%d",E[M][N]);
		    	Sum=Sum+E[M][N];
		    	D=E[M][N];
			}
		    else
		    {
		    	printf(">>END\n");
		    	printf("SUM=%d",Sum);
			}
			E[M][N]=100001;
		}
	}
	
	return 0;
}
