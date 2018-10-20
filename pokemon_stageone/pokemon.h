#ifndef POKEMON_H
#define POKEMON_H

#endif // POKEMON_H

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QString>
#include <QTime>
#include <QDebug>
#include <QtGlobal>

#define MAX_LEVEL 15

/*精灵种类*/
enum pokemonKind {
    highAttack = 0,
    highBlood,
    highDefense,
    highSpeed,
};

const QList<QString> POKEMONKIND = {"HighAttack", "HighBlood", "HighDefense", "HighSpeed"};

/*稀有度*/
enum Rarity {
    N = 0, R, SR, SSR, UR,
};

const QList<QString> RARITY = {"N", "R", "SR", "SSR", "UR"};

/*技能*/
enum BaseSkill
{
    buring = 0,
    frozen,
    bloodsucking,
};

const QList<QString> BASESKILL = {};

/*不同稀有度的属性基础乘积系数*/
const double UForMain = 0.05;
const double RForMain = 0.1;
const double SRForMain = 0.3;
const double SSRForMain = 0.8;
const double URForMain = 1.0;

const double UForNormal = 0;
const double RForNormal = 0.03;
const double SRForNormal = 0.1;
const double SSRForNormal = 0.15;
const double URForNormal = 0.2;



class Pokemon : public QObject
{
    Q_OBJECT
public:
    Pokemon():level(1),exp(0){}
    virtual ~Pokemon(){}

    QString getName();
    QString getAllAttritubeInfo();
    unsigned int getLevel();
    void expUp(unsigned int exp);
    virtual QString getRace(){};
    virtual QString getUltimateSkill(){};


    virtual void levelUp(){}
    virtual void skillAttack(){}

protected:
    /*pokemon's attribute*/
    QString name;
    unsigned int level;
    unsigned int exp;
    unsigned int cur_exp;
    unsigned int base_attack; //基础攻击力
    unsigned int defense_power; //基础防御力
    unsigned int max_hp; //最大生命值
    unsigned int battle_hp; //当前生命值
    unsigned int wsp; //攻击速度
    unsigned int avoid; //回避率
    unsigned int critical; //暴击率

    pokemonKind kind; //精灵种类
    Rarity rarity; //稀有度
    BaseSkill baseSkill; //基础技能技能

    void setBaseSkill();
    void setRarity();
    virtual void setKind(){}
    //virtual void setRarity(){}
    virtual void setRace(){}
    virtual void setUltimateSkill(){}
    virtual void setBaseAttribute(unsigned int _base_attack,
                          unsigned int _defense_power,
                          unsigned int _max_hp,
                          unsigned int _wsp,
                          unsigned int _avoid,
                          unsigned int _critical);

};
