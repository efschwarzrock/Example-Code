/*
 * Tests2.cpp
 *
 *  Created on: Feb 7, 2019
 *      Author: Erich Schwarzrock
 */

#include "Tests2.h"
#include "Grid.h"
#include "Ant.h"
#include "Doodlebug.h"
#include <iostream>


Tests2::Tests2() {
	// TODO Auto-generated constructor stub
	//initialize the grid
}

bool Tests2::doTests()
{
	bool results;
	//establish a grid
	bool ok1 = gridTest();
	if(ok1){
		std::cout << "ok1" << std::endl;
	}
	//populate it with ants
	bool ok2 = makeAntsTest();
	if(ok2){
		std::cout << "ok2" << std::endl;
	}
	//see whether they move
	bool ok3 = antsMoveTest();
	if(ok3){
		std::cout << "ok3" << std::endl;
	}

	//see whether they breed
	bool ok4 = antsBreedTest();
	if(ok4){
		std::cout << "ok4" << std::endl;
	}
	//see whether they die?
	bool ok5 = antsDieTest();//maybe if they wander off?
	if(ok5){
		std::cout << "ok5" << std::endl;
	}
	//populate with doodlebugs
	bool ok6 = makeDoodlesTest();
	if(ok6){
		std::cout << "ok6" << std::endl;
	}
	//see whether they move
	bool ok7 = doodleMoveTest();
	if(ok7){
		std::cout << "ok7" << std::endl;
	}
	//see whether they breed
	bool ok8 = doodleBreedTest();
	if(ok8){
		std::cout << "ok8" << std::endl;
	}
	//see whether they eat ants
	bool ok9 = doodleEatTest();
	if(ok9){
		std::cout << "ok9" << std::endl;
	}
	//see whether they die
	bool ok10 = doodleDietest();
	if(ok10){
		std::cout << "ok10" << std::endl;
	}




	results = ok1 && ok2 && ok3 && ok4 && ok5 && ok6 && ok7 && ok8 && ok9 && ok10;
	return results;

}
bool Tests2::gridTest()
{
	bool result = true;
	bool ok1 = true;
	bool ok2 = true;
	std::cout << "Running the grid test" << std::endl;
	Grid* myGrid = new Grid(8);
	if(myGrid->getCellOccupant(2, 3)!=empty)
	{
		std::cout << "Cell not initially empty" << std::endl;
		ok1 = false;
	}
	//std::cout << "second grid test" << std::endl;
	Ant* a1 = new Ant(2, 3, myGrid);
	if(myGrid->getCellOccupant(2, 3)!=ant)
	{
		std::cout << "Cell not set to ant" << std::endl;
		ok2 = false;
	}
	//std::cout << "third grid test" << std::endl;
	delete myGrid;
	result = ok1 && ok2;
	return result;
}
bool Tests2::makeAntsTest()
{
	bool result = true;
	bool ok1 = true;
	bool ok2 = true;
	std::cout << "Running the make ants test" << std::endl;

	Grid* myGrid_p = new Grid(9);
	if(myGrid_p->getCellOccupant(1, 2)!=empty)
	{
		std::cout << "Cell 1,2 not initially empty" << std::endl;
	}
	Ant* a1 = new Ant(1, 2, myGrid_p);
	if(myGrid_p->getCellOccupant(1, 2)!=ant)
	{
		std::cout << "Cell not set to ant" << std::endl;
		ok1 = false;
	}
	if(myGrid_p->getCellOccupant(3, 4)!=empty)
	{
		std::cout << "Cell 3,4 not initially empty" << std::endl;
	}
	Ant* a2 = new Ant(3, 4, myGrid_p);
	if(myGrid_p->getCellOccupant(3, 4)!=ant)
	{
		std::cout << "Cell not set to ant" << std::endl;
		ok2 = false;
	}
	myGrid_p->setCellOccupant(3, 4, empty, nullptr);
	delete a1;
	delete myGrid_p;
	result = ok1 && ok2;
	return result;
}
bool Tests2::antsMoveTest()
{
	bool result = true;
	std::cout << "Running the move ants test" << std::endl;

	bool oka = false;
	Grid* grida = new Grid(1);
	Ant* aa1 = new Ant(0, 0, grida);
	aa1->move();
	oka = (grida->getCellOccupant(0, 0) == ant);

	bool okb = false;
	Grid* gridb = new Grid(2);
	Ant* ab1 = new Ant(0, 0, gridb);
	Ant* ab2 = new Ant(1, 0, gridb);
	ab1->move();
	okb = (gridb->getCellOccupant(0, 0) == empty && gridb->getCellOccupant(0, 1) == ant && gridb->getCellOccupant(1, 1) == empty);

	bool okc = false;
	Grid* gridc = new Grid(2);
	Ant* ac1 = new Ant(0, 0, gridb);
	Ant* ac2 = new Ant(0, 1, gridb);
	ac1->move();
	okc = (gridc->getCellOccupant(0, 0) == empty && gridc->getCellOccupant(1, 0) == ant && gridc->getCellOccupant(1, 1) == empty);

	bool okd = false;
	Grid* gridd = new Grid(2);
	Ant* ad1 = new Ant(1, 1, gridb);
	Ant* ad2 = new Ant(1, 0, gridb);
	ad1->move();
	okd = (gridd->getCellOccupant(1, 1) == empty && gridd->getCellOccupant(0, 1) == ant && gridd->getCellOccupant(0, 0) == empty);

	bool oke = false;
	Grid* gride = new Grid(2);
	Ant* ae1 = new Ant(0, 1, gridb);
	Ant* ae2 = new Ant(1, 1, gridb);
	ae1->move();
	oke = (gride->getCellOccupant(0, 0) == ant && gride->getCellOccupant(0, 1) == empty && gride->getCellOccupant(1, 0) == empty);

	bool okf = false;
	Grid* gridf = new Grid(3);
	Ant* af1 = new Ant(1, 1, gridf);
	Ant* af2 = new Ant(1, 0, gridf);
	Ant* af3 = new Ant(0, 1, gridf);
	Ant* af4 = new Ant(2, 1, gridf);
	Ant* af5 = new Ant(1, 2, gridf);
	af1->move();
	okf = (gridf->getCellOccupant(0, 0) == empty && gridf->getCellOccupant(1, 1) == ant && gridf->getCellOccupant(0, 2) == empty
			&& gridf->getCellOccupant(2, 2) == empty && gridf->getCellOccupant(2, 0) == empty);


	bool okg = false;
	Grid* gridg = new Grid(3);
	Ant* ag1 = new Ant(1, 1, gridf);
	ag1->move();
	okg = (gridg->getCellOccupant(0, 0) == empty && gridg->getCellOccupant(1, 1) == empty && gridg->getCellOccupant(0, 2) == empty
			&& gridg->getCellOccupant(2, 2) == empty && gridg->getCellOccupant(2, 0) == empty &&
			(gridg->getCellOccupant(0, 1) == ant || gridg->getCellOccupant(1, 0) == ant
					|| gridg->getCellOccupant(1, 2) == ant || gridg->getCellOccupant(2, 1) == ant));

	delete aa1;

	delete ab1;
	delete ab2;

	delete ac1;
	delete ac2;

	delete ad1;
	delete ad2;

	delete ae1;
	delete ae2;

	delete af1;
	delete af2;
	delete af3;
	delete af4;
	delete af5;

	delete ag1;

	delete grida;
	delete gridb;
	delete gridc;
	delete gridd;
	delete gride;
	delete gridf;
	delete gridg;

	result = oka && okb && okc && okd && oke && okf && okg;
	return result;
}
bool Tests2::antsBreedTest()
{
	bool result = true;
	std::cout << "Running the breed ants test" << std::endl;

	bool oka = false;
	Grid* grida = new Grid(1);
	Ant* aa1 = new Ant(0, 0, grida);
	aa1->move();
	aa1->move();
	aa1->move();
	Ant* aa2 = aa1->breed();
	oka = (aa2 == nullptr);

	bool okb = false;
	Grid* gridb = new Grid(2);
	Ant* ab1 = new Ant(0, 0, gridb);
	Ant* ab2 = new Ant(1, 0, gridb);
	Ant* ab3 = new Ant(1, 1, gridb);
	ab1->move();
	ab1->move();
	ab1->move();
	Ant* ab4 = ab1->breed();
	okb = (ab4 != nullptr && gridb->getCellOccupant(0, 0) == ant && gridb->getCellOccupant(0, 1) == ant);

	bool okc = false;
	Grid* gridc = new Grid(2);
	Ant* ac1 = new Ant(0, 1, gridc);
	Ant* ac2 = new Ant(1, 0, gridc);
	Ant* ac3 = new Ant(1, 1, gridc);
	ac1->move();
	ac1->move();
	ac1->move();
	Ant* ac4 = ac1->breed();
	okc = (ac4 != nullptr && gridc->getCellOccupant(0, 0) == ant && gridc->getCellOccupant(0, 1) == ant);

	bool okd = false;
	Grid* gridd = new Grid(2);
	Ant* ad1 = new Ant(0, 0, gridd);
	Ant* ad2 = new Ant(1, 1, gridd);
	Ant* ad3 = new Ant(0, 1, gridd);
	ad1->move();
	ad1->move();
	ad1->move();
	Ant* ad4 = ad1->breed();
	okd = (ad4 != nullptr && gridd->getCellOccupant(0, 0) == ant && gridd->getCellOccupant(1, 0) == ant);

	bool oke = false;
	Grid* gride = new Grid(2);
	Ant* ae1 = new Ant(1, 0, gride);
	Ant* ae2 = new Ant(1, 1, gride);
	Ant* ae3 = new Ant(0, 1, gride);
	ae1->move();
	ae1->move();
	ae1->move();
	Ant* ae4 = ae1->breed();
	oke = (ae4 != nullptr && gride->getCellOccupant(0, 0) == ant && gride->getCellOccupant(1, 0) == ant);

	bool okf = false;
	Grid* gridf = new Grid(3);
	Ant* af1 = new Ant(1, 1, gridf);
	Ant* af2 = new Ant(1, 0, gridf);
	Ant* af3 = new Ant(0, 1, gridf);
	Ant* af4 = new Ant(2, 1, gridf);
	Ant* af5 = new Ant(1, 2, gridf);
	af1->move();
	af1->move();
	af1->move();
	Ant* af6 = af1->breed();
	af1->move();
	gridf->setCellOccupant(1, 0, empty, nullptr);
	gridf->setCellOccupant(1, 2, empty, nullptr);
	gridf->setCellOccupant(0, 1, empty, nullptr);
	gridf->setCellOccupant(2, 1, empty, nullptr);
	Ant* af7 = af1->breed();
	okf = (af6 == nullptr && af7 != nullptr &&
			gridf->getCellOccupant(0, 0) == empty && gridf->getCellOccupant(2, 0) == empty &&
			gridf->getCellOccupant(0, 2) == empty && gridf->getCellOccupant(2, 2) == empty &&
			gridf->getCellOccupant(1, 1) == ant &&
			(gridf->getCellOccupant(1, 0) == ant || gridf->getCellOccupant(0, 1) == ant ||
			 gridf->getCellOccupant(1, 2) == ant || gridf->getCellOccupant(2, 1) == ant));

	bool okg = false;
	Grid* gridg = new Grid(3);
	Ant* ag1 = new Ant(0, 0, gridg);
	Ant* ag2 = new Ant(1, 0, gridg);
	Ant* ag3 = new Ant(1, 1, gridg);
	Ant* ag4 = new Ant(1, 2, gridg);
	ag1->move();
	ag1->move();
	ag1->move();
	Ant* ag5 = ag1->breed();
	okg = (ag5 != nullptr && gridg->getCellOccupant(0, 1) == ant && gridg->getCellOccupant(0, 0) != gridg->getCellOccupant(0, 2)
			&& (gridg->getCellOccupant(0, 0) == ant || gridg->getCellOccupant(0, 2) == ant));

	bool okh = false;
	Grid* gridh = new Grid(3);
	Ant* ah1 = new Ant(0, 0, gridh);
	Ant* ah2 = new Ant(0, 1, gridh);
	Ant* ah3 = new Ant(1, 1, gridh);
	Ant* ah4 = new Ant(2, 1, gridh);
	ah1->move();
	ah1->move();
	ah1->move();
	Ant* ah5 = ah1->breed();
	okh = (ah5 != nullptr && gridh->getCellOccupant(1, 0) == ant && gridh->getCellOccupant(0, 0) != gridh->getCellOccupant(2, 0)
			&& (gridh->getCellOccupant(0, 0) == ant || gridh->getCellOccupant(2, 0) == ant));

	bool oki = false;
	Grid* gridi = new Grid(3);
	Ant* ai1 = new Ant(0, 0, gridi);
	ai1->move();
	ai1->move();
	Ant* ai2 = ai1->breed();
	ai1->move();
	Ant* ai3 = ai1->breed();
	ai1->move();
	ai1->move();
	Ant* ai4 = ai1->breed();
	oki = (ai2 == nullptr && ai3 != nullptr && ai4 == nullptr);

	delete aa1;
	delete aa2;

	delete ab1;
	delete ab2;
	delete ab3;
	delete ab4;

	delete ac1;
	delete ac2;
	delete ac3;
	delete ac4;

	delete ad1;
	delete ad2;
	delete ad3;
	delete ad4;

	delete ae1;
	delete ae2;
	delete ae3;
	delete ae4;

	delete af1;
	delete af6;
	delete af7;

	delete ag1;
	delete ag2;
	delete ag3;
	delete ag4;
	delete ag5;

	delete ah1;
	delete ah2;
	delete ah3;
	delete ah4;
	delete ah5;

	delete ai1;
	delete ai2;
	delete ai3;
	delete ai4;

	delete grida;
	delete gridb;
	delete gridc;
	delete gridd;
	delete gride;
	delete gridf;
	delete gridg;
	delete gridh;
	delete gridi;

	result = oka && okb && okc && okd && oke && okf && okg && okh && oki;
	return result;
}
bool Tests2::antsDieTest()
{
	bool result = true;
	std::cout << "Running the ants die test" << std::endl;
	Grid* grida = new Grid(1);
	Ant* aa1 = new Ant(0, 0, grida);
	aa1->die();
	result = (grida->getCellOccupant(0, 0) == empty);
	delete grida;
	return result;
}
bool Tests2::makeDoodlesTest()
{
	bool result = true;
		bool ok1 = true;
		bool ok2 = true;
		std::cout << "Running the make doodle test" << std::endl;

		Grid* myGrid_p = new Grid(9);
		if(myGrid_p->getCellOccupant(1, 2)!=empty)
		{
			std::cout << "Cell 1,2 not initially empty" << std::endl;
		}
		Doodlebug* d1 = new Doodlebug(1, 2, myGrid_p);
		if(myGrid_p->getCellOccupant(1, 2)!=doodlebug)
		{
			std::cout << "Cell not set to doodlebug" << std::endl;
			ok1 = false;
		}
		if(myGrid_p->getCellOccupant(3, 4)!=empty)
		{
			std::cout << "Cell 3,4 not initially empty" << std::endl;
		}
		Doodlebug* d2 = new Doodlebug(3, 4, myGrid_p);
		if(myGrid_p->getCellOccupant(3, 4)!=doodlebug)
		{
			std::cout << "Cell not set to doodlebug" << std::endl;
			ok2 = false;
		}
		myGrid_p->setCellOccupant(3, 4, empty, nullptr);
		delete d1;
		delete myGrid_p;
		result = ok1 && ok2;
		return result;
}
bool Tests2::doodleMoveTest()
{
	bool result = true;
	std::cout << "Running the move doodlebugs test" << std::endl;

	bool oka = false;
	Grid* grida = new Grid(1);
	Doodlebug* da1 = new Doodlebug(0, 0, grida);
	da1->move();
	oka = (grida->getCellOccupant(0, 0) == doodlebug);

	bool okb = false;
	Grid* gridb = new Grid(2);
	Doodlebug* db1 = new Doodlebug(0, 0, gridb);
	Doodlebug* db2 = new Doodlebug(1, 0, gridb);
	db1->move();
	okb = (gridb->getCellOccupant(0, 0) == empty && gridb->getCellOccupant(0, 1) == doodlebug && gridb->getCellOccupant(1, 1) == empty);

	bool okc = false;
	Grid* gridc = new Grid(2);
	Doodlebug* dc1 = new Doodlebug(0, 0, gridb);
	Doodlebug* dc2 = new Doodlebug(0, 1, gridb);
	dc1->move();
	okc = (gridc->getCellOccupant(0, 0) == empty && gridc->getCellOccupant(1, 0) == doodlebug && gridc->getCellOccupant(1, 1) == empty);

	bool okd = false;
	Grid* gridd = new Grid(2);
	Doodlebug* dd1 = new Doodlebug(1, 1, gridb);
	Doodlebug* dd2 = new Doodlebug(1, 0, gridb);
	dd1->move();
	okd = (gridd->getCellOccupant(1, 1) == empty && gridd->getCellOccupant(0, 1) == doodlebug && gridd->getCellOccupant(0, 0) == empty);

	bool oke = false;
	Grid* gride = new Grid(2);
	Doodlebug* de1 = new Doodlebug(0, 1, gridb);
	Doodlebug* de2 = new Doodlebug(1, 1, gridb);
	de1->move();
	oke = (gride->getCellOccupant(0, 0) == doodlebug && gride->getCellOccupant(0, 1) == empty && gride->getCellOccupant(1, 0) == empty);

	bool okf = false;
	Grid* gridf = new Grid(3);
	Doodlebug* df1 = new Doodlebug(1, 1, gridf);
	Doodlebug* df2 = new Doodlebug(1, 0, gridf);
	Doodlebug* df3 = new Doodlebug(0, 1, gridf);
	Doodlebug* df4 = new Doodlebug(2, 1, gridf);
	Doodlebug* df5 = new Doodlebug(1, 2, gridf);
	df1->move();
	okf = (gridf->getCellOccupant(0, 0) == empty && gridf->getCellOccupant(1, 1) == doodlebug && gridf->getCellOccupant(0, 2) == empty
			&& gridf->getCellOccupant(2, 2) == empty && gridf->getCellOccupant(2, 0) == empty);


	bool okg = false;
	Grid* gridg = new Grid(3);
	Doodlebug* dg1 = new Doodlebug(1, 1, gridf);
	dg1->move();
	okg = (gridg->getCellOccupant(0, 0) == empty && gridg->getCellOccupant(1, 1) == empty && gridg->getCellOccupant(0, 2) == empty
			&& gridg->getCellOccupant(2, 2) == empty && gridg->getCellOccupant(2, 0) == empty &&
			(gridg->getCellOccupant(0, 1) == doodlebug || gridg->getCellOccupant(1, 0) == doodlebug
					|| gridg->getCellOccupant(1, 2) == doodlebug || gridg->getCellOccupant(2, 1) == doodlebug));





	bool okh = false;
	Grid* gridh = new Grid(3);
	Doodlebug* dh1 = new Doodlebug(1, 1, gridh);
	Ant* ah1 = new Ant(1, 0, gridh);
	dh1->move();
	okh = (gridh->getCellOccupant(1, 1) == empty && gridh->getCellOccupant(1, 0) == doodlebug);





	bool oki = false;
	Grid* gridi = new Grid(3);
	Doodlebug* di1 = new Doodlebug(1, 1, gridi);
	Ant* ai1 = new Ant(0, 1, gridi);
	di1->move();
	oki = (gridi->getCellOccupant(1, 1) == empty && gridi->getCellOccupant(0, 1) == doodlebug);

	bool okj = false;
	Grid* gridj = new Grid(3);
	Doodlebug* dj1 = new Doodlebug(1, 1, gridj);
	Ant* aj1 = new Ant(1, 2, gridj);
	dj1->move();
	okj = (gridj->getCellOccupant(1, 1) == empty && gridj->getCellOccupant(1, 2) == doodlebug);

	bool okk = false;
	Grid* gridk = new Grid(3);
	Doodlebug* dk1 = new Doodlebug(1, 1, gridk);
	Ant* ak1 = new Ant(2, 1, gridk);
	dk1->move();
	okk = (gridk->getCellOccupant(1, 1) == empty && gridk->getCellOccupant(2, 1) == doodlebug);

	bool okl = false;
	Grid* gridl = new Grid(3);
	Doodlebug* dl1 = new Doodlebug(1, 1, gridl);
	Ant* al1 = new Ant(2, 1, gridl);
	Ant* al2 = new Ant(0, 1, gridl);
	Ant* al3 = new Ant(1, 2, gridl);
	Ant* al4 = new Ant(1, 0, gridl);
	dl1->move();
	okl = (gridl->getCellOccupant(1, 1) == empty && (
			(gridl->getCellOccupant(2, 1) == doodlebug && gridl->getCellOccupant(0, 1) == ant &&
			gridl->getCellOccupant(1, 0) == ant && gridl->getCellOccupant(1, 2) == ant)
			||
			(gridl->getCellOccupant(2, 1) == ant && gridl->getCellOccupant(0, 1) == doodlebug &&
			gridl->getCellOccupant(1, 0) == ant && gridl->getCellOccupant(1, 2) == ant)
			||
			(gridl->getCellOccupant(2, 1) == ant && gridl->getCellOccupant(0, 1) == ant &&
			gridl->getCellOccupant(1, 0) == doodlebug && gridl->getCellOccupant(1, 2) == ant)
			||
			(gridl->getCellOccupant(2, 1) == ant && gridl->getCellOccupant(0, 1) == ant &&
			gridl->getCellOccupant(1, 0) == ant && gridl->getCellOccupant(1, 2) == doodlebug)));

	delete da1;

	delete db1;
	delete db2;

	delete dc1;
	delete dc2;

	delete dd1;
	delete dd2;

	delete de1;
	delete de2;

	delete df1;
	delete df2;
	delete df3;
	delete df4;
	delete df5;

	delete dg1;

	delete dh1;

	delete di1;

	delete dj1;

	delete dk1;

	delete dl1;

	delete grida;
	delete gridb;
	delete gridc;
	delete gridd;
	delete gride;
	delete gridf;
	delete gridg;
	delete gridh;
	delete gridi;
	delete gridj;
	delete gridk;
	delete gridl;

	result = oka && okb && okc && okd && oke && okf && okg && okh && oki && okj && okk && okl;
	return result;
}
bool Tests2::doodleBreedTest()
{

	bool result = true;
	std::cout << "Running the breed doodlebug test" << std::endl;

	bool oka = false;
	Grid* grida = new Grid(1);
	Doodlebug* da1 = new Doodlebug(0, 0, grida);
	da1->move();
	da1->move();
	da1->move();
	da1->move();

	da1->move();
	da1->move();
	da1->move();
	da1->move();
	Doodlebug* da2 = da1->breed();
	oka = (da2 == nullptr);

	bool okb = false;
	Grid* gridb = new Grid(2);
	Doodlebug* db1 = new Doodlebug(0, 0, gridb);
	Doodlebug* db2 = new Doodlebug(1, 0, gridb);
	Doodlebug* db3 = new Doodlebug(1, 1, gridb);
	db1->move();
	db1->move();
	db1->move();
	db1->move();

	db1->move();
	db1->move();
	db1->move();
	db1->move();
	Doodlebug* db4 = db1->breed();
	okb = (db4 != nullptr && gridb->getCellOccupant(0, 0) == doodlebug && gridb->getCellOccupant(0, 1) == doodlebug);

	bool okc = false;
	Grid* gridc = new Grid(2);
	Doodlebug* dc1 = new Doodlebug(0, 1, gridc);
	Doodlebug* dc2 = new Doodlebug(1, 0, gridc);
	Doodlebug* dc3 = new Doodlebug(1, 1, gridc);
	dc1->move();
	dc1->move();
	dc1->move();
	dc1->move();

	dc1->move();
	dc1->move();
	dc1->move();
	dc1->move();
	Doodlebug* dc4 = dc1->breed();
	okc = (dc4 != nullptr && gridc->getCellOccupant(0, 0) == doodlebug && gridc->getCellOccupant(0, 1) == doodlebug);

	bool okd = false;
	Grid* gridd = new Grid(2);
	Doodlebug* dd1 = new Doodlebug(0, 0, gridd);
	Doodlebug* dd2 = new Doodlebug(1, 1, gridd);
	Doodlebug* dd3 = new Doodlebug(0, 1, gridd);
	dd1->move();
	dd1->move();
	dd1->move();
	dd1->move();

	dd1->move();
	dd1->move();
	dd1->move();
	dd1->move();
	Doodlebug* dd4 = dd1->breed();
	okd = (dd4 != nullptr && gridd->getCellOccupant(0, 0) == doodlebug && gridd->getCellOccupant(1, 0) == doodlebug);

	bool oke = false;
	Grid* gride = new Grid(2);
	Doodlebug* de1 = new Doodlebug(1, 0, gride);
	Doodlebug* de2 = new Doodlebug(1, 1, gride);
	Doodlebug* de3 = new Doodlebug(0, 1, gride);
	de1->move();
	de1->move();
	de1->move();
	de1->move();

	de1->move();
	de1->move();
	de1->move();
	de1->move();
	Doodlebug* de4 = de1->breed();
	oke = (de4 != nullptr && gride->getCellOccupant(0, 0) == doodlebug && gride->getCellOccupant(1, 0) == doodlebug);

	bool okf = false;
	Grid* gridf = new Grid(3);
	Doodlebug* df1 = new Doodlebug(1, 1, gridf);
	Doodlebug* df2 = new Doodlebug(1, 0, gridf);
	Doodlebug* df3 = new Doodlebug(0, 1, gridf);
	Doodlebug* df4 = new Doodlebug(2, 1, gridf);
	Doodlebug* df5 = new Doodlebug(1, 2, gridf);
	df1->move();
	df1->move();
	df1->move();
	df1->move();

	df1->move();
	df1->move();
	df1->move();
	df1->move();
	Doodlebug* df6 = df1->breed();
	df1->move();
	gridf->setCellOccupant(1, 0, empty, nullptr);
	gridf->setCellOccupant(1, 2, empty, nullptr);
	gridf->setCellOccupant(0, 1, empty, nullptr);
	gridf->setCellOccupant(2, 1, empty, nullptr);
	Doodlebug* df7 = df1->breed();
	okf = (df6 == nullptr && df7 != nullptr &&
			gridf->getCellOccupant(0, 0) == empty && gridf->getCellOccupant(2, 0) == empty &&
			gridf->getCellOccupant(0, 2) == empty && gridf->getCellOccupant(2, 2) == empty &&
			gridf->getCellOccupant(1, 1) == doodlebug &&
			(gridf->getCellOccupant(1, 0) == doodlebug || gridf->getCellOccupant(0, 1) == doodlebug ||
			 gridf->getCellOccupant(1, 2) == doodlebug || gridf->getCellOccupant(2, 1) == doodlebug));

	bool okg = false;
	Grid* gridg = new Grid(3);
	Doodlebug* dg1 = new Doodlebug(0, 1, gridg);
	Doodlebug* dg2 = new Doodlebug(1, 0, gridg);
	Doodlebug* dg3 = new Doodlebug(1, 1, gridg);
	Doodlebug* dg4 = new Doodlebug(1, 2, gridg);
	dg1->move();
	dg1->move();
	dg1->move();
	dg1->move();

	dg1->move();
	dg1->move();
	dg1->move();
	dg1->move();
	Doodlebug* dg5 = dg1->breed();
	okg = (dg5 != nullptr && gridg->getCellOccupant(0, 1) == doodlebug && gridg->getCellOccupant(0, 0) != gridg->getCellOccupant(0, 2)
			&& (gridg->getCellOccupant(0, 0) == doodlebug || gridg->getCellOccupant(0, 2) == doodlebug));

	bool okh = false;
	Grid* gridh = new Grid(3);
	Doodlebug* dh1 = new Doodlebug(1, 0, gridh);
	Doodlebug* dh2 = new Doodlebug(0, 1, gridh);
	Doodlebug* dh3 = new Doodlebug(1, 1, gridh);
	Doodlebug* dh4 = new Doodlebug(2, 1, gridh);
	dh1->move();
	dh1->move();
	dh1->move();
	dh1->move();

	dh1->move();
	dh1->move();
	dh1->move();
	dh1->move();
	Doodlebug* dh5 = dh1->breed();
	okh = (dh5 != nullptr && gridh->getCellOccupant(1, 0) == doodlebug && gridh->getCellOccupant(0, 0) != gridh->getCellOccupant(2, 0)
			&& (gridh->getCellOccupant(0, 0) == doodlebug || gridh->getCellOccupant(2, 0) == doodlebug));

	bool oki = false;
	Grid* gridi = new Grid(3);
	Doodlebug* di1 = new Doodlebug(0, 0, gridi);
	di1->move();
	di1->move();
	di1->move();
	di1->move();

	di1->move();
	di1->move();
	di1->move();
	Doodlebug* di2 = di1->breed();
	di1->move();
	Doodlebug* di3 = di1->breed();
	di1->move();
	di1->move();
	Doodlebug* di4 = di1->breed();
	oki = (di2 == nullptr && di3 != nullptr && di4 == nullptr);

	delete da1;
	delete da2;

	delete db1;
	delete db2;
	delete db3;
	delete db4;

	delete dc1;
	delete dc2;
	delete dc3;
	delete dc4;

	delete dd1;
	delete dd2;
	delete dd3;
	delete dd4;

	delete de1;
	delete de2;
	delete de3;
	delete de4;

	delete df1;
	delete df6;
	delete df7;

	delete dg1;
	delete dg2;
	delete dg3;
	delete dg4;
	delete dg5;

	delete dh1;
	delete dh2;
	delete dh3;
	delete dh4;
	delete dh5;

	delete di1;
	delete di2;
	delete di3;
	delete di4;

	delete grida;
	delete gridb;
	delete gridc;
	delete gridd;
	delete gride;
	delete gridf;
	delete gridg;
	delete gridh;
	delete gridi;

	result = oka && okb && okc && okd && oke && okf && okg && okh && oki;
	return result;
}
bool Tests2::doodleEatTest()
{
	bool result = true;
	std::cout << "Running the eat ant test" << std::endl;

	bool okh = false;
	Grid* gridh = new Grid(3);
	Doodlebug* dh1 = new Doodlebug(1, 1, gridh);
	Ant* ah1 = new Ant(1, 0, gridh);
	dh1->eat(1);
	okh = (gridh->getCellOccupant(1, 1) == empty && gridh->getCellOccupant(1, 0) == doodlebug);

	bool oki = false;
	Grid* gridi = new Grid(3);
	Doodlebug* di1 = new Doodlebug(1, 1, gridi);
	Ant* ai1 = new Ant(0, 1, gridi);
	di1->eat(1);
	oki = (gridi->getCellOccupant(1, 1) == empty && gridi->getCellOccupant(0, 1) == doodlebug);

	bool okj = false;
	Grid* gridj = new Grid(3);
	Doodlebug* dj1 = new Doodlebug(1, 1, gridj);
	Ant* aj1 = new Ant(1, 2, gridj);
	dj1->eat(1);
	okj = (gridj->getCellOccupant(1, 1) == empty && gridj->getCellOccupant(1, 2) == doodlebug);

	bool okk = false;
	Grid* gridk = new Grid(3);
	Doodlebug* dk1 = new Doodlebug(1, 1, gridk);
	Ant* ak1 = new Ant(2, 1, gridk);
	dk1->eat(1);
	okk = (gridk->getCellOccupant(1, 1) == empty && gridk->getCellOccupant(2, 1) == doodlebug);

	bool okl = false;
	Grid* gridl = new Grid(3);
	Doodlebug* dl1 = new Doodlebug(1, 1, gridl);
	Ant* al1 = new Ant(2, 1, gridl);
	Ant* al2 = new Ant(0, 1, gridl);
	Ant* al3 = new Ant(1, 2, gridl);
	Ant* al4 = new Ant(1, 0, gridl);
	dl1->eat(4);
	okl = (gridl->getCellOccupant(1, 1) == empty && (
			(gridl->getCellOccupant(2, 1) == doodlebug && gridl->getCellOccupant(0, 1) == ant &&
			gridl->getCellOccupant(1, 0) == ant && gridl->getCellOccupant(1, 2) == ant)
			||
			(gridl->getCellOccupant(2, 1) == ant && gridl->getCellOccupant(0, 1) == doodlebug &&
			gridl->getCellOccupant(1, 0) == ant && gridl->getCellOccupant(1, 2) == ant)
			||
			(gridl->getCellOccupant(2, 1) == ant && gridl->getCellOccupant(0, 1) == ant &&
			gridl->getCellOccupant(1, 0) == doodlebug && gridl->getCellOccupant(1, 2) == ant)
			||
			(gridl->getCellOccupant(2, 1) == ant && gridl->getCellOccupant(0, 1) == ant &&
			gridl->getCellOccupant(1, 0) == ant && gridl->getCellOccupant(1, 2) == doodlebug)));

	delete dh1;

	delete di1;

	delete dj1;

	delete dk1;

	delete dl1;

	delete gridh;
	delete gridi;
	delete gridj;
	delete gridk;
	delete gridl;

	result = okh && oki && okj && okk && okl;
	return result;
}
bool Tests2::doodleDietest()
{
	bool result = true;
	std::cout << "Running the doodlebug dies test" << std::endl;

	bool oka = false;
	Grid* grida = new Grid(1);
	Doodlebug* da1 = new Doodlebug(0, 0, grida);
	da1->move();
	da1->move();
	bool oka1 = !da1->starved();
	da1->move();
	bool oka2 = da1->starved();
	oka = (oka2 && oka1 && grida->getCellOccupant(0, 0) == empty);

	bool okb = false;
	Grid* gridb = new Grid(2);
	Doodlebug* db1 = new Doodlebug(0, 0, gridb);
	Ant* ab1 = new Ant(0, 1, gridb);
	db1->move();
	db1->move();
	db1->move();
	bool okb1 = !db1->starved();
	db1->move();
	bool okb2 = db1->starved();
	okb = (okb1 && okb2);

	bool okc = false;
	Grid* gridc = new Grid(2);
	Doodlebug* dc1 = new Doodlebug(0, 0, gridc);
	dc1->move();
	dc1->move();
	Ant* ac1 = new Ant(0, 1, gridc);
	dc1->move();
	bool okc1 = !dc1->starved();
	dc1->move();
	bool okc2 = !dc1->starved();
	dc1->move();
	dc1->move();
	bool okc3 = dc1->starved();
	okc = (okc1 && okc2 && okc3);

	delete grida;
	delete gridb;
	delete gridc;
	result = (oka && okb && okc);
	return result;
}

Tests2::~Tests2() {
	// TODO Auto-generated destructor stub
}

