// Public Game Civ version 1.1.0
// Released into the public domain under CC0

#include <stdio.h>
#include <stdlib.h>

int main()
{
	srand(time(NULL));
	int ath = 1,year = 0 - 1500,tp = 0,rnd,tl = 1,res = 10,rpls = 1,ep = 1,defn = 0,alnc = 0;
	char v;
	char civ_name[20];
	printf("PUBLIC DOMAIN SOFTWARE");
	printf("\nPublic Game Civ 1.1.0");
	printf("\nCivilization name:");
	scanf("%s",&civ_name);
	do
	{
		rnd = rand() % 15 + 1;
		if (rnd == 1)
		{
			printf("\nGolden age");
			res+=10;
			tp++;
		}
		else if (rnd == 2)
		{
			printf("\nCrisis");
			if (res > 10) res-=10;
			else res--;
			ath--;
			tp--;
			alnc = 0;
		}
		else if (rnd == 3)
		{
			printf("\nAlien Attack");
			if (ep == 1)
			{
				rnd = rand() % 10 + 1;
			}
			else if (ep == 2)
			{
				rnd = rand() % 50 + 1;
			}
			else if (ep == 3)
			{
				rnd = rand() % 150 + 1;
			}
			else if (ep == 4)
			{
				rnd = rand() % 500 + 1;
			}
			else if (ep == 5)
			{
				rnd = rand() % 850 + 1;
			}
			if (res > rnd)
			{
				printf("\nWin");
				res += 5;
				ath += 1;
			}
			else
			{
				printf("\nFailed");
				rnd = rand() % 2 + 1;
				if ((rnd == 1) && (defn == 1))
				{
					printf("\nThe defense worked. The enemy did not pass");
					defn = 0;
				}
				else
				{
					if (tl < 11)
					{
						res -= rand() % 10 - tl + 1;
						ath -= rand() % 4 + 1;
					}
					else
					{
						ath--;
						res -= 5;
					}
					rpls--;
				}
			}
		}
		else if ((rnd == 4) && (alnc == 0))
		{
			printf("\nNeighboring civilizations offer an alliance");
			printf("\ny/n?");
			scanf(" %c",&v);
			if (v == 'y')
			{
				res+=rand() % 5 + 1;
				tp++;
				alnc = 1;
			}
		}
		else if ((rnd == 5) && (res < 0))
		{
			printf("\nPart of the influence has been sold");
			res = 0;
			res += rand() % 10 + 1;
			ath--;
		}
		else if ((rnd == 6) && (ath > 50))
		{
			printf("\nDivision of the Empire!");
			ath = ath / 2;
			res = res / 2;
			rpls-=5;
		}
		else if ((rnd == 7) && (alnc == 1))
		{
			printf("\nA civilization in alliance with us offers trade exchange");
			printf("\na - technologies,b - resources,c - territories");
			scanf(" %c",&v);
			if (v == 'a')
			{
				tl--;
				res+=rand() % 30 + 1;
				alnc = 0;
			}
			else if ((v == 'b') && (res > 20))
			{
				res-=20;
				tp+=3;
				ath+=rand() % 5 + 1;
				alnc = 0;
			}
			else if (v == 'c')
			{
				ath-=rand() % 5 + 1;
				res+=rand() % 30 + 1;
				alnc = 0;
			}
			else
			{
				printf("\nThe exchange did not take place");
			}
		}
		else if ((rnd == 8) && (alnc == 1))
		{
			printf("\nAssociate refuses to cooperate with us");
			alnc = 0;
			ath--;
		}
		printf("\nCivilization %s",civ_name);
		printf("\nAuthority - %d",ath);
		printf("\nResources - %d",res);
		printf("\nTechnological level - %d",tl);
		printf("\nYear - %d",year);
		printf("\na - research,b - develop infrastructure,c - raid,d - propose an alliance");
		scanf(" %c",&v);
		year+=10;
		res += rpls;
		res -= ath - 1;
		if (year == 0 - 1200)
		{
			ep = 2;
		}
		else if (year == 0 - 500)
		{
			ep = 3;
		}
		else if (year == 1000)
		{
			ep = 4;
		}
		else if (year == 2000)
		{
			ep = 5;
		}
		if (ath > 50)
		{
			printf("\nEmpire");
		}
		if (tp > 3)
		{
			printf("\nA completely new discovery!");
			tl++;
			res+=7;
			ath+=2;
			tp = 0;
		}
		if (res < 1)
		{
			printf("\nHunger!");
			rnd = rand() % 3 + 1;
			if (rnd == 1)
			{
				printf("\nAn uprising has occurred!");
				ath-=rand() % 4 + 1;
			}
		}
		if (res > 1000)
		{
			printf("\nInflation!");
			res-=10;
			rpls-=10;
		}
		if ((v == 'a') && (res > 5))
		{
			res-=5;
			tp++;
		}
		else if ((v == 'b') && (res > 7))
		{
			printf("\na - manufacturing,b - military defense");
			scanf(" %c",&v);
			if (v == 'a')
			{
				if ((rpls < 15) && (ath < 9))
				{
					rpls++;
				}
				else if ((rpls < 40) && (ath > 10) && (ath < 29))
				{
					rpls++;
				}
				else if ((rpls < 40) && (ath == 10))
				{
					rpls++;
				}
				else if (ath > 30)
				{
					rpls++;
				}
				else
				{
					printf("\nLimit reached!");
				}
			}
			else if ((v == 'b') && (defn == 0))
			{
				defn = 1;
			}
			else if ((v == 'b') && (defn == 1))
			{
				printf("\nAlready have");
				res+=7;
			}
			res-=7;
		}
		else if ((v == 'c') && (res > 10))
		{
			res-=10;
			rnd = rand() % 2 + 1;
			if (rnd == 1)
			{
				printf("\nWin");
				res += rand() % 5 + 1;
				ath += rand() % 3 + 1;
			}
			else
			{
				printf("\nFailed");
				rnd = rand() % 2 + 1;
				if ((rnd == 1) && (defn == 1))
				{
					printf("\nThe defense worked. The enemy did not pass");
					defn = 0;
				}
				else
				{
					if (tl < 11)
					{
						res -= rand() % 10 - tl + 1;
						ath -= rand() % 4 + 1;
					}
					else
					{
						ath--;
						res -= 5;
					}
					rpls-=4;
				}
			}
		}
		else if ((v == 'd') && (res > 15))
		{
			if (alnc == 0)
			{
				res-=15;
				rnd = rand() % 2 + 1;
				if (rnd == 1)
				{
					printf("\nOffer accepted");
					ath++;
					res += rand() % 20 + 1;
					alnc = 1;
				}
				else
				{
					printf("\nOffer rejected");
				}
			}
			else
			{
				printf("\nWe are already in an alliance. Break off cooperation?");
				printf("\ny/n?");
				scanf(" %c",&v);
				if (v == 'y')
				{
					alnc = 0;
					res-=15;
				}
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