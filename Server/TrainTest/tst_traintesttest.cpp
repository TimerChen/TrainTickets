#include <QString>
#include <QtTest>
#include <QIODevice>

#include "include/vector.hpp"
#include "include/map.hpp"
#include "include/train.h"

class TrainTestTest : public QObject
{
	Q_OBJECT

public:
	TrainTestTest();

private Q_SLOTS:
	void initTestCase();
	void cleanupTestCase();
	void testCase1_data();
	void testCase1();
};

TrainTestTest::TrainTestTest()
{
}

void TrainTestTest::initTestCase()
{
}

void TrainTestTest::cleanupTestCase()
{
}

void TrainTestTest::testCase1_data()
{
	/*
	QTest::addColumn<QString>("station");
	QTest::newRow("0") << QString();*/
}

void TrainTestTest::testCase1()
{
	using namespace ttd;
	int i,j,seattn = 5,stan = 20;
	Train train("AI-233");
	QDate qdate(2017,3,20),qd0(0,0,0);
	QTime qtime(7,10),qtstep(0,3);
	QDateTime qdt(qd0,qtime);
	ttd::vector<QString>staName;
	ttd::vector<int> mAge;
	ttd::vector<QDateTime> rTime;
	ttd::vector<QDateTime> lTime;
	ttd::vector<QString> seType;
	ttd::vector<int> seNumber;
	ttd::vector<ttd::vector<int> > pTable;
	for( i=0; i<seattn; ++i )
	{
		seType.push_back(QString('A'+i));
		//if(i < seattn-1)
		seNumber.push_back(200);
		pTable.push_back(vector<int>(stan));
	}
	for( i=0; i<stan; ++i )
	{
		staName.push_back( "S-" + QString('A'+i) );
		mAge.push_back(i*3+1);
		rTime.push_back(qdt);
		qdt.addSecs(60*3);
		lTime.push_back(qdt);
		qdt.addSecs(60*3);
		for( j = 0; j < seattn; ++j )
		{
			pTable[j][i] = (i+1)*(j+1);
		}
	}
	train.reconstructe(seattn,stan,
					   staName, mAge,
					   rTime, lTime,
					   seType,seNumber,
					   pTable);
	train.openOneDay( qdate );
	Train::RestTicketsInformation rti;
	QDate dback = qdate;
	qdate = qdate.addDays(10);

	rti = train.showRestTickets(qdate,"S-A","S-S","B");
	qDebug() << (train.salingDate.find(qdate)==train.salingDate.end()) ;
	qDebug() << (qdate < dback) ;
	qDebug() << (qdate > dback) ;
	qDebug() << (qdate == dback) ;

	QCOMPARE(int(pTable.size()),5);
	QCOMPARE((int)pTable[4].size(),20);
	QCOMPARE(pTable[1][17],18*2);
	QCOMPARE(rti.restTicketsNumber,0);
	QCOMPARE(rti.restTicketsPrice,18*2);
	QVERIFY2(true, "Failure");
}

QTEST_APPLESS_MAIN(TrainTestTest)

#include "tst_traintesttest.moc"
