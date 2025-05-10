// Public Game Civ version 1.0.0
// Released into the public domain under CC0

#include <stdio.h>
#include <stdlib.h>

int main()
{
	srand(time(NULL));
	int ath = 1,year = 0 - 1500,tp = 0,rnd,tl = 1,res = 10,rpls = 1;
	char v;
	printf("PUBLIC DOMAIN SOFTWARE");
	printf("\nPublic Game Civ 1.0.0");
	do
	{
		rnd = rand() % 10 + 1;
		if (rnd == 1)
		{
			printf("\nGolden age");
			res+=10;
			ath+=2;
			tp++;
		}
		else if (rnd == 2)
		{
			printf("\nCrisis");
			if (res > 10) res-=10;
			else res--;
			ath--;
			tp--;
		}
		else if (rnd == 3)
		{
			printf("\nAlien Attack");
			rnd = rand() % 30 + 1;
			if (res > rnd)
			{
				printf("\nWin");
				res += rand() % 9 + 1;
				ath += rand() % 3 + 1;
			}
			else
			{
				printf("\nFailed");
				res -= rand() % 9 + 1;
				ath -= rand() % 3 + 1;
				rpls--;
			}
		}
		else if (rnd == 4)
		{
			printf("\nNeighboring civilizations offer an alliance");
			printf("\ny/n?");
			scanf(" %c",&v);
			if (v == 'y')
			{
				res+=rand() % 5 + 1;
				tp++;
			}
		}
		printf("\nAuthority - %d",ath);
		printf("\nResources - %d",res);
		printf("\nTechnological level - %d",tl);
		printf("\nYear - %d",year);
		printf("\na - research,b - develop infrastructure,c - raid");
		scanf(" %c",&v);
		year+=10;
		res += rpls;
		res -= ath - 1;
		if (ath > 50)
		{
			printf("\nEmpire");
		}
		if (tp == 3)
		{
			printf("\nA completely new discovery!");
			tl++;
			res+=7;
			tp = 0;
		}
		if (res < 1)
		{
			printf("\nHunger!");
		}
		if ((v == 'a') && (res > 5))
		{
			res-=5;
			tp++;
		}
		else if ((v == 'b') && (res > 7))
		{
			res-=7;
			rpls++;
		}
		else if ((v == 'c') && (res > 10))
		{
			res-=10;
			rnd = rand() % 2 + 1;
			if (rnd == 1)
			{
				printf("\nWin");
				res += rand() % 9 + 1;
				ath += rand() % 3 + 1;
			}
			else
			{
				printf("\nFailed");
				res -= rand() % 9 + 1;
				ath -= rand() % 3 + 1;
				rpls--;
			}
		}
		else
		{
			printf("\nAction not possible");
		}
	}
	while (ath > 0);
	printf("\nEnd game");
	return 0;
}