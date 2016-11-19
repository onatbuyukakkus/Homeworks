#include <stdio.h>

int main()
{
	int membrane[10001];
	int membrane_Length;
	int virus_Number;
	int virus_Width;
	int virus_Height;
	int first_Attack_Time;
	int first_Attack_Position;
	int speed;
	int time;
	int attack_Number;
	int i;
	int j;
	int k;
	int l;
	int m;
	scanf("%d", &membrane_Length);
	scanf("%d", &virus_Number);	
	for (i=0; i<=membrane_Length; i++)
	{
		membrane[i]=1;	
	}
	for (j=0; j<virus_Number; j++)	
	{
		scanf("%d %d %d %d %d %d %d", &virus_Width, &virus_Height, &first_Attack_Time, &first_Attack_Position, &speed, &time, &attack_Number);
		for (l=0; l< attack_Number; l++)		
		{			
			for (k=first_Attack_Position; k<first_Attack_Position + virus_Width; k++)
			{
				if (virus_Height > membrane[k])
				{
					membrane[k] = virus_Height;
				}
				first_Attack_Position = first_Attack_Position + speed*time;
			}
		}	
	}
	for (m=0; m<membrane_Length; m++)
	{
		printf(" %d", membrane[m]);	
	}
return 0;
}
