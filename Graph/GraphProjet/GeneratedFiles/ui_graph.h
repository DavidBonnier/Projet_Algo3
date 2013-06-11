/********************************************************************************
** Form generated from reading UI file 'graph.ui'
**
** Created: Tue 11. Jun 23:41:12 2013
**      by: Qt User Interface Compiler version 4.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRAPH_H
#define UI_GRAPH_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDockWidget>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QPushButton>
#include <QtGui/QRadioButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GraphClass
{
public:
    QAction *actionOuvrir;
    QAction *actionSauver;
    QAction *actionSauver_sous;
    QAction *actionFermer;
    QAction *actionQuitter;
    QAction *actionOuvrir_une_Image;
    QAction *actionG_rer_les_villes;
    QAction *actionG_rer_les_routes;
    QAction *actionChoix_r_pertoire;
    QAction *actionRestaurer;
    QAction *actionAide;
    QAction *actionA_propos;
    QAction *actionG_rer_les_parcours;
    QAction *actionA_Propos;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_4;
    QMenuBar *menuBar;
    QMenu *menuFichier;
    QMenu *menuOutils;
    QMenu *menuOption;
    QMenu *menuA_propos;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QDockWidget *dockWidgetGestionVilles;
    QWidget *dockWidgetContents;
    QVBoxLayout *verticalLayout;
    QRadioButton *radioButtonAddVilles;
    QRadioButton *radioButtonSuppVille;
    QSpacerItem *verticalSpacer;
    QDockWidget *dockWidgetGestionRoutes;
    QWidget *dockWidgetContents_3;
    QVBoxLayout *verticalLayout_3;
    QRadioButton *radioButtonSaisiRoute;
    QRadioButton *radioButtonSuppRoute;
    QSpacerItem *verticalSpacer_2;
    QDockWidget *dockWidgetGestionParcours;
    QWidget *dockWidgetContents_4;
    QVBoxLayout *verticalLayout_2;
    QRadioButton *radioButtonVilleDep;
    QRadioButton *radioButtonVilleFin;
    QPushButton *pushButtonClearParcours;
    QSpacerItem *verticalSpacer_3;

    void setupUi(QMainWindow *GraphClass)
    {
        if (GraphClass->objectName().isEmpty())
            GraphClass->setObjectName(QString::fromUtf8("GraphClass"));
        GraphClass->resize(600, 690);
        actionOuvrir = new QAction(GraphClass);
        actionOuvrir->setObjectName(QString::fromUtf8("actionOuvrir"));
        actionSauver = new QAction(GraphClass);
        actionSauver->setObjectName(QString::fromUtf8("actionSauver"));
        actionSauver_sous = new QAction(GraphClass);
        actionSauver_sous->setObjectName(QString::fromUtf8("actionSauver_sous"));
        actionFermer = new QAction(GraphClass);
        actionFermer->setObjectName(QString::fromUtf8("actionFermer"));
        actionQuitter = new QAction(GraphClass);
        actionQuitter->setObjectName(QString::fromUtf8("actionQuitter"));
        actionOuvrir_une_Image = new QAction(GraphClass);
        actionOuvrir_une_Image->setObjectName(QString::fromUtf8("actionOuvrir_une_Image"));
        actionG_rer_les_villes = new QAction(GraphClass);
        actionG_rer_les_villes->setObjectName(QString::fromUtf8("actionG_rer_les_villes"));
        actionG_rer_les_villes->setCheckable(true);
        actionG_rer_les_villes->setChecked(true);
        actionG_rer_les_routes = new QAction(GraphClass);
        actionG_rer_les_routes->setObjectName(QString::fromUtf8("actionG_rer_les_routes"));
        actionG_rer_les_routes->setCheckable(true);
        actionChoix_r_pertoire = new QAction(GraphClass);
        actionChoix_r_pertoire->setObjectName(QString::fromUtf8("actionChoix_r_pertoire"));
        actionRestaurer = new QAction(GraphClass);
        actionRestaurer->setObjectName(QString::fromUtf8("actionRestaurer"));
        actionAide = new QAction(GraphClass);
        actionAide->setObjectName(QString::fromUtf8("actionAide"));
        actionA_propos = new QAction(GraphClass);
        actionA_propos->setObjectName(QString::fromUtf8("actionA_propos"));
        actionG_rer_les_parcours = new QAction(GraphClass);
        actionG_rer_les_parcours->setObjectName(QString::fromUtf8("actionG_rer_les_parcours"));
        actionG_rer_les_parcours->setCheckable(true);
        actionA_Propos = new QAction(GraphClass);
        actionA_Propos->setObjectName(QString::fromUtf8("actionA_Propos"));
        centralWidget = new QWidget(GraphClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout_4 = new QVBoxLayout(centralWidget);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        GraphClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(GraphClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 21));
        menuFichier = new QMenu(menuBar);
        menuFichier->setObjectName(QString::fromUtf8("menuFichier"));
        menuOutils = new QMenu(menuBar);
        menuOutils->setObjectName(QString::fromUtf8("menuOutils"));
        menuOption = new QMenu(menuBar);
        menuOption->setObjectName(QString::fromUtf8("menuOption"));
        menuA_propos = new QMenu(menuBar);
        menuA_propos->setObjectName(QString::fromUtf8("menuA_propos"));
        GraphClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(GraphClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        GraphClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(GraphClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        GraphClass->setStatusBar(statusBar);
        dockWidgetGestionVilles = new QDockWidget(GraphClass);
        dockWidgetGestionVilles->setObjectName(QString::fromUtf8("dockWidgetGestionVilles"));
        dockWidgetGestionVilles->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 170, 0);"));
        dockWidgetGestionVilles->setWindowTitle(QString::fromUtf8("Gestion des villes"));
        dockWidgetContents = new QWidget();
        dockWidgetContents->setObjectName(QString::fromUtf8("dockWidgetContents"));
        verticalLayout = new QVBoxLayout(dockWidgetContents);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        radioButtonAddVilles = new QRadioButton(dockWidgetContents);
        radioButtonAddVilles->setObjectName(QString::fromUtf8("radioButtonAddVilles"));
        radioButtonAddVilles->setChecked(true);

        verticalLayout->addWidget(radioButtonAddVilles);

        radioButtonSuppVille = new QRadioButton(dockWidgetContents);
        radioButtonSuppVille->setObjectName(QString::fromUtf8("radioButtonSuppVille"));

        verticalLayout->addWidget(radioButtonSuppVille);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        dockWidgetGestionVilles->setWidget(dockWidgetContents);
        GraphClass->addDockWidget(static_cast<Qt::DockWidgetArea>(1), dockWidgetGestionVilles);
        dockWidgetGestionRoutes = new QDockWidget(GraphClass);
        dockWidgetGestionRoutes->setObjectName(QString::fromUtf8("dockWidgetGestionRoutes"));
        dockWidgetGestionRoutes->setEnabled(true);
        dockWidgetGestionRoutes->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 0);"));
        dockWidgetGestionRoutes->setWindowTitle(QString::fromUtf8("Gestion des routes"));
        dockWidgetContents_3 = new QWidget();
        dockWidgetContents_3->setObjectName(QString::fromUtf8("dockWidgetContents_3"));
        verticalLayout_3 = new QVBoxLayout(dockWidgetContents_3);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        radioButtonSaisiRoute = new QRadioButton(dockWidgetContents_3);
        radioButtonSaisiRoute->setObjectName(QString::fromUtf8("radioButtonSaisiRoute"));
        radioButtonSaisiRoute->setChecked(true);

        verticalLayout_3->addWidget(radioButtonSaisiRoute);

        radioButtonSuppRoute = new QRadioButton(dockWidgetContents_3);
        radioButtonSuppRoute->setObjectName(QString::fromUtf8("radioButtonSuppRoute"));

        verticalLayout_3->addWidget(radioButtonSuppRoute);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_2);

        dockWidgetGestionRoutes->setWidget(dockWidgetContents_3);
        GraphClass->addDockWidget(static_cast<Qt::DockWidgetArea>(1), dockWidgetGestionRoutes);
        dockWidgetGestionParcours = new QDockWidget(GraphClass);
        dockWidgetGestionParcours->setObjectName(QString::fromUtf8("dockWidgetGestionParcours"));
        dockWidgetGestionParcours->setStyleSheet(QString::fromUtf8("background-color: rgb(85, 255, 255);"));
        dockWidgetGestionParcours->setWindowTitle(QString::fromUtf8("Gestion des parcours"));
        dockWidgetContents_4 = new QWidget();
        dockWidgetContents_4->setObjectName(QString::fromUtf8("dockWidgetContents_4"));
        verticalLayout_2 = new QVBoxLayout(dockWidgetContents_4);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        radioButtonVilleDep = new QRadioButton(dockWidgetContents_4);
        radioButtonVilleDep->setObjectName(QString::fromUtf8("radioButtonVilleDep"));
        radioButtonVilleDep->setChecked(true);

        verticalLayout_2->addWidget(radioButtonVilleDep);

        radioButtonVilleFin = new QRadioButton(dockWidgetContents_4);
        radioButtonVilleFin->setObjectName(QString::fromUtf8("radioButtonVilleFin"));

        verticalLayout_2->addWidget(radioButtonVilleFin);

        pushButtonClearParcours = new QPushButton(dockWidgetContents_4);
        pushButtonClearParcours->setObjectName(QString::fromUtf8("pushButtonClearParcours"));
        pushButtonClearParcours->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));

        verticalLayout_2->addWidget(pushButtonClearParcours);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_3);

        dockWidgetGestionParcours->setWidget(dockWidgetContents_4);
        GraphClass->addDockWidget(static_cast<Qt::DockWidgetArea>(1), dockWidgetGestionParcours);

        menuBar->addAction(menuFichier->menuAction());
        menuBar->addAction(menuOutils->menuAction());
        menuBar->addAction(menuOption->menuAction());
        menuBar->addAction(menuA_propos->menuAction());
        menuFichier->addAction(actionOuvrir);
        menuFichier->addAction(actionSauver);
        menuFichier->addAction(actionSauver_sous);
        menuFichier->addAction(actionFermer);
        menuFichier->addAction(actionQuitter);
        menuOutils->addAction(actionOuvrir_une_Image);
        menuOutils->addSeparator();
        menuOutils->addAction(actionG_rer_les_villes);
        menuOutils->addAction(actionG_rer_les_routes);
        menuOutils->addAction(actionG_rer_les_parcours);
        menuOption->addAction(actionChoix_r_pertoire);
        menuOption->addAction(actionRestaurer);
        menuA_propos->addAction(actionA_Propos);

        retranslateUi(GraphClass);

        QMetaObject::connectSlotsByName(GraphClass);
    } // setupUi

    void retranslateUi(QMainWindow *GraphClass)
    {
        GraphClass->setWindowTitle(QApplication::translate("GraphClass", "Graph", 0, QApplication::UnicodeUTF8));
        actionOuvrir->setText(QApplication::translate("GraphClass", "Ouvrir", 0, QApplication::UnicodeUTF8));
        actionSauver->setText(QApplication::translate("GraphClass", "Sauver", 0, QApplication::UnicodeUTF8));
        actionSauver_sous->setText(QApplication::translate("GraphClass", "Sauver sous", 0, QApplication::UnicodeUTF8));
        actionFermer->setText(QApplication::translate("GraphClass", "Fermer", 0, QApplication::UnicodeUTF8));
        actionQuitter->setText(QApplication::translate("GraphClass", "Quitter", 0, QApplication::UnicodeUTF8));
        actionOuvrir_une_Image->setText(QApplication::translate("GraphClass", "Ouvrir une Image", 0, QApplication::UnicodeUTF8));
        actionG_rer_les_villes->setText(QApplication::translate("GraphClass", "G\303\251rer les villes", 0, QApplication::UnicodeUTF8));
        actionG_rer_les_routes->setText(QApplication::translate("GraphClass", "G\303\251rer les routes", 0, QApplication::UnicodeUTF8));
        actionChoix_r_pertoire->setText(QApplication::translate("GraphClass", "Choix r\303\251pertoire", 0, QApplication::UnicodeUTF8));
        actionRestaurer->setText(QApplication::translate("GraphClass", "Restaurer", 0, QApplication::UnicodeUTF8));
        actionAide->setText(QApplication::translate("GraphClass", "Aide", 0, QApplication::UnicodeUTF8));
        actionA_propos->setText(QApplication::translate("GraphClass", "A propos", 0, QApplication::UnicodeUTF8));
        actionG_rer_les_parcours->setText(QApplication::translate("GraphClass", "G\303\251rer les parcours", 0, QApplication::UnicodeUTF8));
        actionA_Propos->setText(QApplication::translate("GraphClass", "A Propos", 0, QApplication::UnicodeUTF8));
        menuFichier->setTitle(QApplication::translate("GraphClass", "Fichier", 0, QApplication::UnicodeUTF8));
        menuOutils->setTitle(QApplication::translate("GraphClass", "Outils", 0, QApplication::UnicodeUTF8));
        menuOption->setTitle(QApplication::translate("GraphClass", "Option", 0, QApplication::UnicodeUTF8));
        menuA_propos->setTitle(QApplication::translate("GraphClass", "? ", 0, QApplication::UnicodeUTF8));
        radioButtonAddVilles->setText(QApplication::translate("GraphClass", "Ajouter une ville", 0, QApplication::UnicodeUTF8));
        radioButtonSuppVille->setText(QApplication::translate("GraphClass", "Supprimer une ville", 0, QApplication::UnicodeUTF8));
        radioButtonSaisiRoute->setText(QApplication::translate("GraphClass", "Saisir une route", 0, QApplication::UnicodeUTF8));
        radioButtonSuppRoute->setText(QApplication::translate("GraphClass", "Supprimer une route", 0, QApplication::UnicodeUTF8));
        radioButtonVilleDep->setText(QApplication::translate("GraphClass", "Saisir la ville de d\303\251part", 0, QApplication::UnicodeUTF8));
        radioButtonVilleFin->setText(QApplication::translate("GraphClass", "Saisir la ville d'arriv\303\251", 0, QApplication::UnicodeUTF8));
        pushButtonClearParcours->setText(QApplication::translate("GraphClass", "Effacer le parcours", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class GraphClass: public Ui_GraphClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRAPH_H
