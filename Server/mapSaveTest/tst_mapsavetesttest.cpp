#include <QString>
#include <QtTest>
#include <QCoreApplication>
#include <QIODevice>

#include <map>
#include "include/map.hpp"
#include <vector>
#include "include/vector.hpp"

class MapSaveTestTest : public QObject
{
	Q_OBJECT

public:
	std::map<int,int> stdmap;
	ttd::map<int,int> ttdmap;
	std::vector<int> sv;
	ttd::vector<int> tv;

	int N;
	MapSaveTestTest();

private Q_SLOTS:
	void initMapSaveTestTest();
	void testmap();
	void testvector();
	void cleanupMapSaveTestTest();
};

MapSaveTestTest::MapSaveTestTest()
{
}
void MapSaveTestTest::initMapSaveTestTest()
{
	N = 1e5;
	for( int i = 0; i < N; ++i )
	{
		int tmp = rand();
		stdmap[i] = tmp;
		ttdmap[i] = tmp;
	}
	for( int i = 0; i < N; ++i )
	{
		int tmp = rand();
		sv.push_back(tmp);
		tv.push_back(tmp);
	}
}
void MapSaveTestTest::cleanupMapSaveTestTest()
{
	stdmap.clear();
	ttdmap.clear();
}

void MapSaveTestTest::testmap()
{

	QFile file("map.data");
	file.open(QIODevice::WriteOnly);
	QDataStream out(&file);
	out.setVersion(QDataStream::Qt_5_0);
	out << ttdmap;
	file.close();

	ttd::map<int,int> ttdmap2;

	file.open(QIODevice::ReadOnly);
	QDataStream in(&file);
	in.setVersion(QDataStream::Qt_5_0);
	in >> ttdmap2;
	file.close();


	QCOMPARE( size_t(N), ttdmap2.size() );
	for( int i = 0; i < N; ++i)
	{
		//qDebug() <<stdmap[i] << ' '<< ttdmap[i];
		QCOMPARE( ttdmap2[i], stdmap[i] );
	}
	QVERIFY2(true, "Failure");
}
void MapSaveTestTest::testvector()
{
	QFile file("vector.data");
	file.open(QIODevice::WriteOnly);
	QDataStream out(&file);
	out.setVersion(QDataStream::Qt_5_0);
	out << tv;
	file.close();
	qDebug() << tv.size();

	ttd::vector<int> tv2;

	file.open(QIODevice::ReadOnly);
	QDataStream in(&file);
	in.setVersion(QDataStream::Qt_5_0);
	in >> tv2;
	file.close();


	QCOMPARE( size_t(N), tv2.size() );
	for( int i = 0; i < N; ++i)
	{
		//qDebug() <<stdmap[i] << ' '<< ttdmap[i];
		QCOMPARE( tv2[i], tv[i] );
	}
	QVERIFY2(true, "Failure");
}

QTEST_MAIN(MapSaveTestTest)

#include "tst_mapsavetesttest.moc"
