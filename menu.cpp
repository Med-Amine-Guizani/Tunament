#include "PROJJ.CPP"
#include <typeinfo>
#include <map>
void menu();
int main()
{
    menu();
    return 0;
}
void menu()
{
    int mdp = 123;
    int id = 123;
    Tournoi *t = new Tournoi();
    cin >> *t;
    vector<organisateur *> list_org;
    map<int, string> list_rec;
    while (1)
    {
        cout << "----------------------------------------------------" << endl;
        cout << "**************Menu Principale***********************" << endl;
        cout << "         choisir des option suivantes                  " << endl;
        cout << "1)Menu Utilisateur" << endl
             << "2)Menu Organisateur" << endl
             << "3)Menu Administratif" << endl
             << "4)Menu Fichier" << endl;
        int rep1;
        cin >> rep1;
        switch (rep1)
        {
        case 1:
            while (1)
            {
                cout << "**********Menu Utilisateur************" << endl;
                cout << "     choisir des option suivantes     " << endl;
                cout << "1)Consulter resultat d'une epreuve" << endl
                     << "2)Consulter les information relatif a une Equipe " << endl
                     << "3)retourner au menu principale" << endl;
                int rep2;
                cin >> rep2;
                switch (rep2)
                {
                case 1:
                {
                    cout << "saisie le id de l' epreuve" << endl;
                    int ident;
                    cin >> ident;
                   cout<<t->getepr(ident);
                };
                break;

                case 2:
                {
                    Equipe *e;
                    e = t->recherche_equipe();
                    if (typeid(*e) == typeid(solo))
                        cout << static_cast<solo &>(*e) << endl;
                    else if (typeid(*e) == typeid(duo))
                        cout << static_cast<duo &>(*e) << endl;
                    else
                        cout << static_cast<squad &>(*e) << endl;
                };
                break;
                };
                if (rep2 = 3)
                {
                    break;
                }
            };
            break;
        case 2:
        {
            while (1)
            {
                cout << "**************Menu Organisateur***********************" << endl;
                cout << "         choisir des option suivantes                  " << endl;
                cout << "1)Organisateur Epreuve" << endl
                     << "2)Organisateur Juge" << endl
                     << "3)Organisateur Recompense" << endl
                     << "4)retourner au menu principale" << endl;
                int rep4;
                cin >> rep4;
                switch (rep4)
                {
                case 1:
                {
                    cout << "****************identification**************************" << endl;
                    int ide, mdp;
                    cout << "identificateur : ";
                    cin >> ide;
                    for (int i = 0; i < list_org.size(); i++)
                    {
                        if (typeid(*list_org[i]) == typeid(organisateur_Epreuve))
                        {
                            if (list_org[i]->getid() == ide)
                            {
                                while (1)
                                {
                                    cout << "****************Menu Organisateur Epreuve***************" << endl;
                                    cout << "     choisir des option suivantes                " << endl;
                                    cout << "1)Initializer une epreuve" << endl;
                                    cout << "2)ajouter une equipe a une epreuve" << endl
                                         << "3)ajouter une epreuve au tournoi" << endl
                                         << "4)modifier une epreuve  " << endl
                                         << "5)annuler une epreuve" << endl
                                         << "6)retourner au menu des organisateur" << endl
                                         << "7)afficher vos infos"<<endl;
                                    int rep5;
                                    cin >> rep5;
                                    switch (rep5)
                                    {
                                    case 1:
                                    {
                                        int ide;
                                        cout << "donner l'id de l'epreuve qui va etre initializer (start)" << endl;
                                        cin >> ide;
                                        t->getepr(ide).initializer();
                                    }
                                    break;
                                    case 2:
                                    {
                                        // ajouter une equipe a une epreuve el objet hanou howa list_org[i]
                                        list_org[i]->enregistrerEqp(t);
                                    }
                                    break;
                                    case 3:
                                    {
                                        // ajouter une epreuve a un tournoi same thing for the objet (list_org[i]->fonction())

                                        static_cast<organisateur_Epreuve &>(*list_org[i]).creerEpreuve(t);
                                    }
                                    break;
                                    case 4:
                                    {
                                        static_cast<organisateur_Epreuve &>(*list_org[i]).modifier(t);
                                    }
                                    break;
                                    case 5:
                                    {
                                        cout << "donner le id de cette equipe" << endl;
                                        int idepreuve;
                                        cin >> idepreuve;
                                        static_cast<organisateur_Epreuve &>(*list_org[i]).annuler(t, idepreuve);
                                    }
                                    break;
                                    case 7:
                                    {
                                        list_org[i]->afficher();
                                    }
                                    }
                                    if (rep5 == 6)
                                        break;
                                }
                            }
                        }
                    }
                }
                break;
                case 2:
                {
                    cout << "****************identification**************************" << endl;
                    int ide, mdp;
                    cout << "identificateur : ";
                    cin >> ide;
                    for (int i = 0; i < list_org.size(); i++)
                    {
                        if (typeid(*list_org[i]) == typeid(organisateur_Juge))
                        {
                            if (list_org[i]->getid() == ide)
                            {
                                while (1)
                                {
                                    cout << "****************Menu Organisateur Juge***************" << endl;
                                    cout << "     choisir des option suivantes                " << endl;
                                    cout << "1)ajouter une equipe a une epreuve" << endl
                                         << "2)ajouter un Juge au epreuve" << endl
                                         << " 3)supprimer un Juge d'une epreuve" << endl
                                         << " 4)consulter la list des juge d'une epreuve" << endl
                                         << "5)retourner au menu des organisateur" << endl;
                                    int rep6;
                                    cin >> rep6;
                                    switch (rep6)
                                    {
                                    case 1:
                                    {
                                        list_org[i]->enregistrerEqp(t);
                                    }
                                    break;
                                    case 2:
                                    {
                                        static_cast<organisateur_Juge &>(*list_org[i]).Assigner(t);
                                    }
                                    break;
                                    case 3:
                                    {
                                        static_cast<organisateur_Juge &>(*list_org[i]).Supprimer(t);
                                    }
                                    break;
                                    case 4:
                                    {
                                        static_cast<organisateur_Juge &>(*list_org[i]).Afficher_list_Juge(t);
                                    }
                                    break;
                                    }
                                    if (rep6 == 5)
                                        break;
                                }
                            }
                        }
                    }
                }
                break;
                case 3:
                {
                    cout << "****************identification**************************" << endl;
                    int ide, mdp;
                    cout << "identificateur : ";
                    cin >> ide;
                    for (int i = 0; i < list_org.size(); i++)
                    {
                        if (typeid(*list_org[i]) == typeid(organisateur_Recompense))
                        {
                            if (list_org[i]->getid() == ide)
                            {
                                while (1)
                                {
                                    cout << "****************Menu Organisateur Recompense***************" << endl;
                                    cout << "     choisir des option suivantes                " << endl;
                                    cout << "1)ajouter une equipe a une epreuve" << endl
                                         << "2)ajouter une recompense a une epreuve" << endl
                                         << "3)assigne une recompense a une equipe " << endl
                                         << "4)afficher une list des recompense relative a ce organisateur" << endl
                                         << "5)modifier une recompense dans une epreuve" << endl
                                         << "6)retourner au menu des organisateur" << endl;
                                    int rep7;
                                    cin >> rep7;
                                    switch (rep7)
                                    {
                                    case 1:
                                    {
                                        list_org[i]->enregistrerEqp(t);
                                    }
                                    break;
                                    case 2:
                                    {
                                        static_cast<organisateur_Recompense &>(*list_org[i]).Ajouter(t);
                                    }
                                    break;
                                    case 3:
                                    {
                                        static_cast<organisateur_Recompense &>(*list_org[i]).Assigner(t);
                                    }
                                    break;
                                    case 4:
                                    {
                                        static_cast<organisateur_Recompense &>(*list_org[i]).afficher();
                                    }
                                    break;
                                    case 5:
                                    {
                                        cout << "donner l'id de l'epreuve " << endl;
                                        int idep;
                                        cin >> idep;
                                        Epreuve *e = new Epreuve;
                                        int idd;
                                            
                                                cout << "donner l'id de la recompense" << endl;
                                                cin >> idd;
                                                e = &t->getepr(idep);
                                            
                                        
                                        static_cast<organisateur_Recompense &>(*list_org[i]).modifierRecomp(e, idd);
                                    }
                                    break;
                                    }
                                    if (rep7 == 6)
                                        break;
                                }
                            }
                        }
                    }
                }
                }
            case 5:
            {
                break;
            }
            }
            break;
        }

        case 3:
        {
            cout << "**********Identification************" << endl;
            int ide, md;
            cout << "Identifiant: ";
            cin >> ide;
            cout << "Mot de pass: ";
            cin >> md;
            if (md == mdp && ide == id)
            {
                while (1)
                {

                    cout << "**********Menu Administratif************" << endl;
                    cout << "     Vous Voulez ajouter un ...     " << endl;
                    cout << "1)Organisateur Epreuve" << endl
                         << "2)Organisateur Juge " << endl
                         << "3)Organisateur recompanse" << endl;
                    cout << "     Ou Voulez Vous                  " << endl;
                    cout << "4)Consulter list des organisateur  5)retourner au menu principal" << endl;

                    int rep3;
                    cin >> rep3;
                    switch (rep3)
                    {
                    case 1:
                    {
                        organisateur_Epreuve *p = new organisateur_Epreuve;
                        cin >> *p;
                        list_org.push_back(p);
                    };
                    break;
                    case 2:
                    {
                        organisateur_Juge *p = new organisateur_Juge;
                        cin >> *p;
                        list_org.push_back(p);
                    };
                    break;
                    case 3:
                    {
                        organisateur_Recompense *p = new organisateur_Recompense;
                        cin >> *p;
                        list_org.push_back(p);
                    }
                    break;
                    case 4:
                    {
                        for (int i = 0; i < list_org.size(); i++)
                        {
                            if (typeid(list_org) == typeid(organisateur_Epreuve))
                            {
                                cout << "--------------affichage d'un organisateur epreuve" << endl;
                                cout << *list_org[i];
                            }
                            else if (typeid(list_org) == typeid(organisateur_Epreuve))
                            {
                                cout << "--------------affichage d'un organisateur Juge" << endl;
                                cout << *list_org[i];
                            }
                            else
                            {
                                cout << "--------------affichage d'un organisateur Recompense" << endl;
                                cout << *list_org[i];
                            }
                        }
                    }
                    break;
                    }
                    if (rep3 == 5)
                        break;
                }
            }
            else
            {
                cout << "echec d'identification !!!!!!!" << endl;
            }
        };
        break;
        case 4:
        {
            while (1)
            {
                cout << "******************Menu Fichier***************" << endl;
                cout << "1)fichier des equipe relative a une epreuve " << endl;
                cout << "2)fichier des juges relative a une epreuve  " << endl;
                cout << "3)retourner au menu principale" << endl;
                int rep10;
                cin >> rep10;
                switch (rep10)
                {
                case 1:
                {
                    while (1)
                    {
                        cout << "******************Fichier Equipes***************" << endl;
                        cout << "1)enregister les equipes d'une epreuve dans le fichier " << endl;
                        cout << "2)afficher le continue de fichier" << endl;
                        cout << "3)retourner au menu de fichier " << endl;
                        int rep11;
                        cin >> rep11;
                        switch (rep11)
                        {
                        case 1:
                        {
                            cout << "saisir l'id de l'epreuve" << endl;
                            int b;
                            cin >> b;
                            fstream f;
                            t->getepr(b).creerfEqp(f);
                            for (int i = 0; i < t->getepr(b).geteqp().size(); i++)
                            {
                                cout << "******************" << endl;
                                f << *t->getepr(b).geteqp()[i] << endl;
                                cout << "++++++++++++++" << endl;
                            }
                            cout << "eregistrement terminee" << endl;
                            f.close();
                        }
                        break;
                        case 2:
                        {
                            cout << "saisir l'id de l'epreuve" << endl;
                            int b;
                            cin >> b;
                            fstream f;
                            t->getepr(b).LirefEqp(f);
                            f.seekg(0);
                            Equipe *v;
                            while (1)
                            {
                                v = new Equipe;
                                f >> v;
                                if (f.eof())
                                    break;
                                cout << *v << endl;
                            }

                            f.close();
                        }
                        }
                        if (rep11 == 3)
                        {

                            break;
                        }
                    }
                }
                break;
                case 2:
                {
                    while (1)
                    {
                        fstream fj;
                        cout << "******************Fichier Juges******************" << endl;
                        cout << "1)enregister les juges d'une epreuve dans le fichier " << endl;
                        cout << "2)afficher le continue de fichier" << endl;
                        cout << "3)retourner au menu de fichier " << endl;
                        int r;
                        cin >> r;
                        switch (r)
                        {
                        case 1:
                        {
                              cout << "saisir l'id de l'epreuve" << endl;
                            int b;
                            cin >> b;
                            fstream f;
                            t->getepr(b).creefju(f);
                            for (int i = 0; i < t->getepr(b).getju().size(); i++)
                            {
                                cout << "******************" << endl;
                                f << t->getepr(b).getju()[i] << endl;
                                cout << "++++++++++++++" << endl;
                            }
                            cout << "eregistrement terminee" << endl;
                            f.close();
                        }
                        break;
                        case 2:
                        {
                             cout << "saisir l'id de l'epreuve" << endl;
                            int b;
                            cin >> b;
                            fstream o;
                            t->getepr(b).Lirefju(o);
                            o.seekg(0);
                            Juge *v;
                             char ch[100];
    
                            while (1)
                            {
                                v = new Juge;
                                o >> v;
                                if (o.eof())
                                    break;
                                cout << *v << endl;
                            }

                            o.close();
                        }
                        break;
                        case 3:
                        {
                            break;
                        }
                        }
                        
                    }
                }
                }
                if (rep10 = 3)
                    break;
            }
        }
        }
    }
}