#include <QString>
#include <QtTest>
#include <QCoreApplication>

class MapSaveTestTest : public QObject
{
	Q_OBJECT

public:
	MapSaveTestTest();

private Q_SLOTS:
	void testCase1();
};

MapSaveTestTest::MapSaveTestTest()
{
}

void MapSaveTestTest::testCase1()
{
	QVERIFY2(true, "Failure");
}

QTEST_MAIN(MapSaveTestTest)

#include "tst_mapsavetesttest.moc"
