using namespace std;

const int MAXBEERML = 500;
const int MINBEERML = 330;

class Beer
{
public:
	Beer(const char* mark, int ml);
	
	void printAddress();

	void printBeer();
	void setMl(int ml);

	void setMark(const char* mark);

	int getMl() const; // const сложен тук означава, че метода не променя член-данните на класа.Съответно можем да го викаме от константни обекти

	const char* getMark() const;
	
private:

	char mark[20]; //Стринг с максимална дължина 19, понеже 1 символ ни трябва за '\0'
	int ml;
};

Beer::Beer(const char* mark, int ml)
{
	setMark(mark);
	setMl(ml);
}
void Beer::printAddress()
{
	cout << this << endl;
}
void Beer::printBeer()
{
	cout << mark << " " << ml << endl;
}
void Beer::setMl(int ml)
{
	if (ml < MINBEERML)
		ml = MINBEERML;
	else if (ml > MAXBEERML)
		ml = MAXBEERML;
	this->ml = ml;
}
void Beer::setMark(const char* mark)
{
	int len = strlen(mark);

	if (len >= 20 || len == 0) //ако ни дадат невалидна марка на бирата (стринг с дължина >= 20 )
		this->mark[0] = '\0';	//правим марката да е празния стринг 
	else
		strcpy(this->mark, mark);
}
int Beer::getMl() const 
{
	return ml;
}
const char* Beer::getMark() const
{
	return mark;
}


int main()
{
	Beer t("Zagorka", 5); // 5 е невалидно количество бира. Но в конструктора извикваме setML, която се грижи в променливата да не попаднат невалидни данни.
	t.setMl(330);
	t.PrintBeer();
}
