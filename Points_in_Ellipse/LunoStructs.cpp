#include"LunoStructs.h"

#include <QDebug>



//void append_Lunopoints(Lunopoints*& anker, const double x, const double y, int scanFieldid) {
//
//	Lunopoints* neuer_eintrag = new Lunopoints;
//	neuer_eintrag->X = x;
//	neuer_eintrag->Y = y;
//
//	neuer_eintrag->scanFieldId = scanFieldid;
//	neuer_eintrag->next = nullptr;
//
//	if (anker == nullptr) {
//		neuer_eintrag->prev = nullptr;
//		anker = neuer_eintrag;
//	}
//	else
//	{
//		Lunopoints* ptr = anker;
//		while (ptr->next != nullptr) {
//			ptr = ptr->next;
//		}
//		ptr->next = neuer_eintrag;
//		//previous agora aponta para o eintrag antes do ultimo
//		neuer_eintrag->prev = ptr;
//
//	}
//
//	anker->amount++;
//
//}

//void append_Lunopoints(Lunopoints*& anker, const double x, const double y, int processParamid, int scanFieldid) {
//	
//	Lunopoints * neuer_eintrag = new Lunopoints;
//	neuer_eintrag->X = x;
//	neuer_eintrag->Y = y;
//	neuer_eintrag->processParamId = processParamid;
//	neuer_eintrag->scanFieldId = scanFieldid;
//	neuer_eintrag->next = nullptr;
//
//	if (anker == nullptr) {
//		neuer_eintrag->prev = nullptr;
//		anker = neuer_eintrag;
//	}
//	else
//	{
//		Lunopoints* ptr = anker;
//		while (ptr->next != nullptr) {
//			ptr = ptr->next;
//		}
//		ptr->next = neuer_eintrag;
//		//previous agora aponta para o eintrag antes do ultimo
//		neuer_eintrag->prev = ptr;
//
//	}
//
//	anker->amount++;
//
//}
/*double X_Lunopoints_at(Lunopoints* anker, int nummer) {

	if (nummer == 0 || nummer < 0) {
		nummer = 1;
	}

	if (anker == nullptr) {
		qDebug()<<"liste leer";
	}
	else {
		bool da = true;
		Lunopoints* ptr = anker;
		int i = 1;
		while (i != nummer) {
			ptr = ptr->next;
			if (ptr->next == nullptr) {
				qDebug()<< "existiert nicht ";
				da = false;
				break;
			}
			i++;
		}
		if (da)
			return ptr->X;
	}
}


double Y_Lunopoints_at(Lunopoints* anker, int nummer) {
	if (nummer == 0 || nummer < 0) {
		nummer = 1;
	}

	if (anker == nullptr) {
		qDebug() << "liste leer";
	}
	else {
		bool da = true;
		Lunopoints* ptr = anker;
		int i = 1;
		while (i != nummer) {
			ptr = ptr->next;
			if (ptr->next == nullptr) {
				qDebug() << "existiert nicht ";
				da = false;
				break;
			}
			i++;
		}
		if (da)
			return ptr->Y;
	}
}
	
	
int Lunopoints_processParamId_at(Lunopoints * anker, int nummer) {
	if (nummer == 0 || nummer < 0) {
		nummer = 1;
	}

	if (anker == nullptr) {
		qDebug() << "liste leer";
	}
	else {
		bool da = true;
		Lunopoints* ptr = anker;
		int i = 1;
		while (i != nummer) {
			ptr = ptr->next;
			if (ptr->next == nullptr) {
				qDebug() << "existiert nicht ";
				da = false;
				break;
			}
			i++;
		}
		if (da)
			return ptr->processParamId;
	}
	}


int Lunopoints_scanFieldId_at(Lunopoints* anker, int nummer) {
	if (nummer == 0 || nummer < 0) {
		nummer = 1;
	}

	if (anker == nullptr) {
		qDebug() << "liste leer";
	}
	else {
		bool da = true;
		Lunopoints* ptr = anker;
		int i = 1;
		while (i != nummer) {
			ptr = ptr->next;
			if (ptr->next == nullptr) {
				qDebug() << "existiert nicht ";
				da = false;
				break;
			}
			i++;
		}
		if (da)
			return ptr->scanFieldId;
	}
}*/