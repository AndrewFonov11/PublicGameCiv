// Public Game Civ version 1.4.0
// Released into the public domain under CC0

#include <stdio.h>
#include <stdlib.h>

int ath = 1,year = 0 - 1500,tp = 0,rnd,tl = 1,res = 10,rpls = 1,rg = 1,ep = 1,defn = 0,alnc = 0,city = 0,win,pr,tc = 0;
char v;
char civ_name[20];

void rg_()
{
	if (rg == 1) rg = rg;
	if (rg == 2) res--;
	if (rg == 3)
	{
		rnd = rand() % 3 + 1;
		if (rnd == 1) tp++;
	}
}

void type_civ()
{
	rnd = rand() % 4 + 1;
	if (rnd == 1)
	{
		printf("\nPeople from the south");
	}
	else if (rnd == 2)
	{
		printf("\nPeople from the north");
	}
	else if (rnd == 3)
	{
		printf("\nPeople from the East");
	}
	else if (rnd == 4)
	{
		printf("\nPeople from the West");
	}
}

void war()
{
	int wp = res,ww = rnd;
	printf("\nYour army - %d",wp);
	printf("\nEnemy army - %d",ww);
	if (wp > ww)
	{
		win = 1;
		rnd = rand() % 3 + 1;
		if (rnd == 2)
		{
			printf("\nYou have destroyed the enemy city!");
			res += rand() % 15 + 1;
		}
	}
	else if (wp == ww)
	{
		printf("\nDead heat");
		win = 3;
	}
	else if (wp < ww)
	{
		win = 2;
		rnd = rand() % 3 + 1;
		if ((rnd == 2) && (city > 0))
		{
			printf("\nThe enemy destroyed the city!");
			res -= rand() % 15 + 1;
			city --;
			rpls -= rand() % 4 + 1;
		}
	}
	if (win == 1)
	{
		printf("\nWin");
		rnd = rand() % 3 + 1;
		if (rnd == 1)
		{
			tl ++;
		}
		res += rand() % 5 + 1;
		ath += rand() % 3 + 1;
		rnd = rand() % 7 + 1;
		if (rnd == 1)
		{
			printf("\nForce them to pay tribute?");
			printf("\ny/n?");
			scanf(" %c",&v);
			if (v == 'y')
			{
				rpls ++;
			}
		}
		rnd = rand() % 4 + 1;
		if (rnd == 3)
		{
			printf("\nWe have captured the enemy city!");
			city ++;
			ath += rand() % 3 + 1;
			rpls ++;
			res += rand() % 10 + 1;
		}
	}
	else if (win == 2)
	{
		printf("\nFailed");
		rnd = rand() % 3 + 1;
		if (rnd == 1)
		{
			tl --;
		}
		rnd = rand() % 7 + 1;
		if (rnd == 1)
		{
			printf("\nPaying tribute to the enemy");
			rpls --;
		}
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
				ath -= rand() % 5 + 1;
			}
			else
			{
				ath -= rand() % 2 + 1;
				res -= 5;
			}
			rpls -= rand() % 4 + 1;
			rnd = rand() % 4 + 1;
			if ((rnd == 3) && (city > 0))
			{
				printf("\nThe enemies have captured our city!");
				city --;
				rpls --;
				ath -= rand() % 3 + 1;
				res -= rand() % 10 + 1;
			}
		}
	}
}

void random_()
{
	rnd = rand() % 15 + 1;
	if (rnd == 1)
	{
		printf("\nGolden age");
		res += rand() % 12 + 1;
		tp++;
	}
	else if (rnd == 2)
	{
		printf("\nCrisis");
		if (res > 10) res-=10;
		else res--;
		if (ep == 1) ath = ath;
		if (ep == 2) ath --;
		if (ep == 3) ath -= rand() % 3 + 1;
		if (ep == 4) ath -= rand() % 7 + 1;
		if (ep == 5) ath -= rand() % 11 + 2;
		tp--;
		alnc = 0;
		tc = 0;
	}
	else if (rnd == 3)
	{
		printf("\nAlien Attack");
		type_civ();
		if (rnd == tc)
		{
			printf("\nWe are in alliance. Attack is cancelled.");
		}
		else
		{
			if (ep == 1)
			{
				rnd = rand() % 15 + 1;
			}
			else if (ep == 2)
			{
				rnd = rand() % 200 + 1;
			}
			else if (ep == 3)
			{
				rnd = rand() % 500 + 1;
			}
			else if (ep == 4)
			{
				rnd = rand() % 750 + 50;
			}
			else if (ep == 5)
			{
				rnd = rand() % 850 + 150;
			}
			war();
		}
	}
	else if ((rnd == 4) && (alnc == 0))
	{
		type_civ();
		printf("\nNeighboring civilizations offer an alliance");
		printf("\ny/n?");
		scanf(" %c",&v);
		if (v == 'y')
		{
			tc = rnd;
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
		rnd = rand() % 900 + 1;
		war();
		if (win == 2)
		{
			ath = ath / 2;
			res = res / 2;
			city = city / 2;
			rpls-= rand() % 20 + 1;
		}
		else
		{
			printf("\nThe army was able to regain control");
			res -= rand() % 30 + 1;
			rpls-=2;
		}
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
			tc = 0;
			alnc = 0;
		}
		else if ((v == 'b') && (res > 20))
		{
			res-=20;
			tp+=3;
			ath+=rand() % 5 + 1;
			tc = 0;
			alnc = 0;
		}
		else if (v == 'c')
		{
			ath-=rand() % 5 + 1;
			res+=rand() % 30 + 1;
			rnd = rand() % 2 + 1;
			if (rnd == 1)
			{
				city --;
				rpls -= rand() % 2 + 1;
			}
			tc = 0;
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
		tc = 0;
		alnc = 0;
		ath--;
	}
	else if (rnd == 9)
	{
		printf("\nCivilization wishes to join us");
		printf("\ny/n?");
		scanf(" %c",&v);
		if (v == 'y')
		{
			res += rand() % 20 + 1;
			ath++;
			tp+=2;
		}
	}
	else if (rnd == 10)
	{
		if ((tl > 5) && (rg == 1) && (res > 5))
		{
			printf("\nBuild a single temple?");
			printf("\ny/n?");
			scanf(" %c",&v);
			if (v == 'y') rg = 2,res-=5;
		}
		if ((tl > 18) && (rg != 3) && (res > 3))
		{
			printf("\nAccept secularism?");
			printf("\ny/n?");
			scanf(" %c",&v);
			if (v == 'y') rg = 3,res-=3;
		}
	}
}

int main()
{
	srand(time(NULL));
	printf("\nPUBLIC DOMAIN SOFTWARE");
	printf("\nPublic Game Civ 1.4.0");
	printf("\nCivilization name:");
	scanf("%s",&civ_name);
	do
	{
		random_();
		rg_();
		printf("\nCivilization %s",civ_name);
		printf("\nAuthority - %d",ath);
		printf("\nResources - %d",res);
		printf("\nTechnological level - %d",tl);
		printf("\nCity - %d",city);
		printf("\nYear - %d",year);
		printf("\na - research,b - develop infrastructure,c - raid,d - propose an alliance,e - create a city");
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
		if ((city < 6) && (ath > 45))
		{
			printf("\nToo few cities");
			ath = 45;
		}
		if (tp > 3)
		{
			printf("\nA completely new discovery!");
			tl++;
			res += 7;
			ath += rand() % 2 + 1;
			tp = 0;
		}
		if (res < 1)
		{
			printf("\nHunger!");
			rnd = rand() % 3 + 1;
			if (rnd == 1)
			{
				printf("\nAn uprising has occurred!");
				rnd = rand() % 3 + 1;
				if ((rnd == 1) && (rg == 2))
				{
					printf("\nThe priests calmed the crowd");
				}
				else
				{
					ath-=rand() % 4 + 1;
					rnd = rand() % 2 + 1;
					if ((rnd == 1) && (city > 0))
					{
						printf("\nProtests have taken over one of the cities!");
						city --;
						rpls -= rand() % 3 + 1;
					}
				}
			}
		}
		if (res > 1000)
		{
			printf("\nInflation!");
			res-=10;
			rpls-=10;
		}
		if (tl < 1)
		{
			printf("\nThe loss of basic technologies led to the complete degradation of society.");
			city = 0;
			rpls -= 5;
		}
		if ((v == 'a') && (res > 5))
		{
			res -= 5;
			tp++;
		}
		else if ((v == 'b') && (res > 7))
		{
			printf("\na - manufacturing,b - military defense");
			scanf(" %c",&v);
			if (v == 'a')
			{
				
				if ((ath < 3) && (rpls < 7))
				{
					rpls++;
					res -= 7;
				}
				else
				{
					pr = ath * 120 / 100 + city;
					if (rpls < pr)
					{
						rpls++;
						res -= 7;
					}
					else
					{
						printf("\nLimit reached!");
					}
				}
			}
			else if ((v == 'b') && (defn == 0) && (tl > 2))
			{
				defn = 1;
				res -= 7;
			}
			else
			{
				printf("\nAction not possible");
			}
		}
		else if ((v == 'c') && (res > 10))
		{
			type_civ();
			printf("\nLaunch an attack on civilization?");
			printf("\ny/n?");
			scanf(" %c",&v);
			if (v == 'y')
			{
				res -= 10;
				if (rnd == tc) tc = 0,alnc = 0;
				if (ep == 1)
				{
					rnd = rand() % 80 + 1;
				}
				else if (ep == 2)
				{
					rnd = rand() % 450 + 1;
				}
				else if (ep == 3)
				{
					rnd = rand() % 720 + 30;
				}
				else if (ep == 4)
				{
					rnd = rand() % 850 + 50;
				}
				else if (ep == 5)
				{
					rnd = rand() % 800 + 200;
				}
				war();
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
					type_civ();
					printf("\nJoin the alliance?");
					printf("\ny/n?");
					scanf(" %c",&v);
					if (v == 'y')
					{
						tc = rnd;
						ath++;
						res += rand() % 20 + 1;
						alnc = 1;
					}
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
					tc = 0;
					res-=15;
				}
			}
		}
		else if ((v == 'e') && (res > 30) && (tl > 5))
		{
			pr = ath * 20 / 100;
			if (city < pr)
			{
				printf("\nA new city is founded.");
				city ++;
				rpls += rand() % 3 + 1;
				res -= 30;
			}
			else
			{
				printf("\nLimit reached!");
			}
		}
		else if (v == '!')
		{
			printf("\nAre you sure you want to leave the game? Your progress will not be saved.");
			printf("\ny/n?");
			scanf(" %c",&v);
			if (v == 'y')
			{
				return 0;
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