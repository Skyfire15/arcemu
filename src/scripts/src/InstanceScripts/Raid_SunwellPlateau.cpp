/*
 * ArcScript Scripts for Arcemu MMORPG Server
 * Copyright (C) 2008-2009 Arcemu Team 
 * Copyright (C) 2007 Moon++ Team <http://www.moonplusplus.com/>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "StdAfx.h"
#include "Setup.h"
#include "Base.h"

/*

//Kil'Jaeden sound IDs saved for future use
//Some of them are used anytime during the raid progression in the instance (no mechanism for this yet)
//Some others are used in the actual Kil'Jaeden encounter

12527 Sunwell Plateau - Kil Jaeden "Spawning"
12495 Sunwell Plateau - Kil Jaeden - "All my plans have led to this"
12496 Sunwell Plateau - Kil Jaeden - "Stay on task, do not waste time"
12497 Sunwell Plateau - Kil Jaeden - "I've waited long enough!"
12498 Sunwell Plateau - Kil Jaeden - "Fail me, and suffer for eternity!"
12499 Sunwell Plateau - Kil Jaeden - "Drain the girl, drain her power, untill there is nothing but an ...something... shell"
12500 Sunwell Plateau - Kil Jaeden - Very long thing, basiclly he tells us that he will take control over the Burning Legion.
12501 Sunwell Plateau - Kil Jaeden - "Another step towards destruction!"

*/

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Sunblade Protector
#define CN_SUNBLADE_PROTECTOR				25507
#define SUNBLADE_PROTECTOR_FEL_LIGHTNING	46480

class SunbladeProtectorAI : public ArcScriptCreatureAI
{
	ARCSCRIPT_FACTORY_FUNCTION(SunbladeProtectorAI, ArcScriptCreatureAI);
	SunbladeProtectorAI(Creature* pCreature) : ArcScriptCreatureAI(pCreature)
	{
		AddSpell(SUNBLADE_PROTECTOR_FEL_LIGHTNING, Target_RandomPlayer, 100, 0, 15, 0, 60);
	}
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Shadowsword Assassin
#define CN_SHADOWSWORD_ASSASSIN						25484
#define SHADOWSWORD_ASSASSIN_ASSASSINS_MARK			46459
#define SHADOWSWORD_ASSASSIN_AIMED_SHOT				46460
#define SHADOWSWORD_ASSASSIN_SHADOWSTEP				46463
#define SHADOWSWORD_ASSASSIN_GREATER_INVISIBILITY	16380

class ShadowswordAssassinAI : public ArcScriptCreatureAI
{
	ARCSCRIPT_FACTORY_FUNCTION(ShadowswordAssassinAI, ArcScriptCreatureAI);
	ShadowswordAssassinAI(Creature* pCreature) : ArcScriptCreatureAI(pCreature)
	{
		AddSpell(SHADOWSWORD_ASSASSIN_ASSASSINS_MARK, Target_RandomPlayer, 100, 0, 15, 0, 100);
		AddSpell(SHADOWSWORD_ASSASSIN_AIMED_SHOT, Target_Current, 15, 4, 6, 5, 35, true);
		AddSpell(SHADOWSWORD_ASSASSIN_SHADOWSTEP, Target_RandomPlayer, 15, 0, 50, 0, 40);
		AddSpell(SHADOWSWORD_ASSASSIN_GREATER_INVISIBILITY, Target_Self, 5, 0, 180);
	}
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Shadowsword Commander
#define CN_SHADOWSWORD_COMMANDER			25837
#define SHADOWSWORD_COMMANDER_SHIELD_SLAM	46762
#define SHADOWSWORD_COMMANDER_BATTLESHOUT	46763

class ShadowswordCommanderAI : public ArcScriptCreatureAI
{
	ARCSCRIPT_FACTORY_FUNCTION(ShadowswordCommanderAI, ArcScriptCreatureAI);
	ShadowswordCommanderAI(Creature* pCreature) : ArcScriptCreatureAI(pCreature)
	{
		AddSpell(SHADOWSWORD_COMMANDER_SHIELD_SLAM, Target_Current, 10, 0, 10);
		AddSpell(SHADOWSWORD_COMMANDER_BATTLESHOUT, Target_Self, 20, 0, 25);
	}
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Kalecgos
#define CN_KALECGOS					24850
#define KALECGOS_FROST_BREATH		44799
#define KALECGOS_SPECTRAL_BLAST		44866
#define KALECGOS_ARCANE_BUFFET		45018

void SpellFunc_Kalecgos_WildMagic(SpellDesc* pThis, ArcScriptCreatureAI* pCreatureAI, Unit* pTarget, TargetType pType);

class KalecgosAI : public ArcScriptBossAI
{
    ARCSCRIPT_FACTORY_FUNCTION(KalecgosAI, ArcScriptBossAI);
	KalecgosAI(Creature* pCreature) : ArcScriptBossAI(pCreature)
	{
		AddSpell(KALECGOS_FROST_BREATH, Target_Current, 10, 1, 12, 0, 30);
		AddSpellFunc(SpellFunc_Kalecgos_WildMagic, Target_RandomPlayer, 15, 0, 10, 0, 100);
		AddSpell(KALECGOS_SPECTRAL_BLAST, Target_Self, 25, 0, 25, 0, 50);
		AddSpell(KALECGOS_ARCANE_BUFFET, Target_Self, 100, 0, 8);

		//Emotes
		AddEmote(Event_OnCombatStart, "I need... your help... Cannot... resist him... much longer...", Text_Yell);
		AddEmote(Event_OnTargetDied, "In the name of Kil'jaeden!", Text_Yell);
		AddEmote(Event_OnTargetDied, "You were warned! ", Text_Yell);
		AddEmote(Event_OnDied, "I am forever in your debt. Once we have triumphed over Kil'jaeden, this entire world will be in your debt as well.", Text_Yell, 11135);
	}
};

void SpellFunc_Kalecgos_WildMagic(SpellDesc* pThis, ArcScriptCreatureAI* pCreatureAI, Unit* pTarget, TargetType pType)
{
	KalecgosAI* Kalecgos = ( pCreatureAI ) ? (KalecgosAI*)pCreatureAI : NULL;
	if( Kalecgos )
	{
		//TODO
/*
		#define SP_WILD_MAGIC_1			44978
		#define SP_WILD_MAGIC_2			45001
		#define SP_WILD_MAGIC_3			45002
		#define SP_WILD_MAGIC_4			45004
		#define SP_WILD_MAGIC_5			45006
		#define SP_WILD_MAGIC_6			45010*/
	}
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Sathrovarr the Corruptor
#define CN_SATHROVARR_THE_CORRUPTOR							24892
#define SATHROVARR_THE_CORRUPTOR_CURSE_OF_BOUNDLESS_AGONY	45034
#define SATHROVARR_THE_CORRUPTOR_SHADOW_BOLT_VOLLEY			38840
#define SATHROVARR_THE_CORRUPTOR_CORRUPTING_STRIKE			45029

class SathrovarrTheCorruptorAI : public ArcScriptBossAI
{
    ARCSCRIPT_FACTORY_FUNCTION(SathrovarrTheCorruptorAI, ArcScriptBossAI);
	SathrovarrTheCorruptorAI(Creature* pCreature) : ArcScriptBossAI(pCreature)
	{
		AddSpell(SATHROVARR_THE_CORRUPTOR_CURSE_OF_BOUNDLESS_AGONY, Target_RandomPlayer, 20, 0, 12, 0, 40); 
		AddSpell(SATHROVARR_THE_CORRUPTOR_SHADOW_BOLT_VOLLEY, Target_RandomPlayerApplyAura, 20, 1, 25, 0, 40);
		AddSpell(SATHROVARR_THE_CORRUPTOR_CORRUPTING_STRIKE, Target_Current, 30, 0, 5, 0, 10);

		//Emotes
		AddEmote(Event_OnCombatStart, "Gyahaha... There will be no reprieve. My work here is nearly finished.", Text_Yell);
		AddEmote(Event_OnTargetDied, "Pitious mortal!", Text_Yell);
		AddEmote(Event_OnTargetDied, "Haven't you heard? I always win!", Text_Yell);
		AddEmote(Event_OnDied, "I'm... never on... the losing... side...", Text_Yell);
	}
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Brutallus
#define CN_BRUTALLUS			24882
#define BRUTALLUS_METEOR_SLASH	45150
#define BRUTALLUS_BURN			45141
#define BRUTALLUS_STOMP			45185
#define BRUTALLUS_BERSERK		26662

class BrutallusAI : public ArcScriptBossAI
{
    ARCSCRIPT_FACTORY_FUNCTION(BrutallusAI, ArcScriptBossAI);
	BrutallusAI(Creature* pCreature) : ArcScriptBossAI(pCreature)
	{
		AddSpell(BRUTALLUS_METEOR_SLASH, Target_Self, 100, 1, 12);
		AddSpell(BRUTALLUS_BURN, Target_RandomPlayer, 50, 0, 20);
		AddSpell(BRUTALLUS_STOMP, Target_Current, 25, 0, 30);

		//6min Enrage
		SetEnrageInfo(AddSpell(BRUTALLUS_BERSERK, Target_Self, 0, 0, 0, 0, 0, false, "So much for a real challenge... Die!"), 360000);

		//Emotes
		AddEmote(Event_OnCombatStart, "Ah, more lambs to the slaughter!", Text_Yell);
		AddEmote(Event_OnTargetDied, "Perish, insect!", Text_Yell);
		AddEmote(Event_OnTargetDied, "You are meat!", Text_Yell);
		AddEmote(Event_OnTargetDied, "Too easy!", Text_Yell);
		AddEmote(Event_OnDied, "Gah! Well done... Now... this gets... interesting...", Text_Yell);
		AddEmote(Event_OnTaunt, "Bring the fight to me!", Text_Yell);
		AddEmote(Event_OnTaunt, "Another day, another glorious battle!", Text_Yell);
		AddEmote(Event_OnTaunt, "I live for this!", Text_Yell);
	}
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Felmyst
#define CN_FELMYST					25038
#define FELMYST_CLEAVE				19983
#define FELMYST_CORROSION			45866
#define FELMYST_DEMONIC_VAPOR		45402
#define FELMYST_GAS_NOVA			45855
#define FELMYST_NOXIOUS_FUME		47002
#define FELMYST_ENCAPSULATE			45662
#define FELMYST_FOG_OF_CORRUPTION	45717
#define FELMYST_ENRAGE				26662	//Using same as Brutallus for now, need to find actual spell id

class FelmystAI : public ArcScriptBossAI
{
    ARCSCRIPT_FACTORY_FUNCTION(FelmystAI, ArcScriptBossAI);
	FelmystAI(Creature* pCreature) : ArcScriptBossAI(pCreature)
	{
		//Phase 1 spells
		AddPhaseSpell(1, AddSpell(FELMYST_CLEAVE, Target_Current, 6, 0, 10, 0, 5));
		AddPhaseSpell(1, AddSpell(FELMYST_GAS_NOVA, Target_Self, 25, 1, 18));
		AddPhaseSpell(1, AddSpell(FELMYST_ENCAPSULATE, Target_RandomPlayer, 25, 7, 30, 0, 30));
		AddPhaseSpell(1, AddSpell(FELMYST_CORROSION, Target_Current, 20, 0.75f, 35, 0, 30, false, "Choke on your final breath!"));

		//Phase 2 spells
		AddPhaseSpell(2, AddSpell(FELMYST_DEMONIC_VAPOR, Target_RandomPlayer, 10, 0, 20));

		//Phase 3 spells
		//Fog of corruption is the actual breath Felmyst does during his second phase, probably we'll have to spawn it like a creature.
		//AddSpell(FELMYST_FOG_OF_CORRUPTION, Target_RandomPlayerApplyAura, 15, 0, 20, 0, 10); Does not support by the core.

		//10min Enrage
		SetEnrageInfo(AddSpell(FELMYST_ENRAGE, Target_Self, 0, 0, 0, 0, 0, false, "No more hesitation! Your fates are written!"), 600000);

		//Emotes
		AddEmote(Event_OnCombatStart, "Glory to Kil'jaeden! Death to all who oppose!", Text_Yell);
		AddEmote(Event_OnTargetDied, "I kill for the master! ", Text_Yell);
		AddEmote(Event_OnTargetDied, "The end has come!", Text_Yell);
		AddEmote(Event_OnDied, "Kil'jaeden... will... prevail...", Text_Yell);
		AddEmote(Event_OnTaunt, "I am stronger than ever before!", Text_Yell);
	}

	void OnCombatStart(Unit* pTarget)
	{
		ApplyAura(FELMYST_NOXIOUS_FUME);
		ParentClass::OnCombatStart(pTarget);
	}
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Lady Sacrolash
#define CN_LADY_SACROLASH				25165
#define CN_GRAND_WARLOCK_ALYTHESS		25166
#define LADY_SACROLASH_DARK_TOUCHED		45347
#define LADY_SACROLASH_SHADOW_BLADES	45248
#define LADY_SACROLASH_SHADOW_NOVA		45329
#define LADY_SACROLASH_CONFOUNDING_BLOW	45256
#define LADY_SACROLASH_ENRAGE			26662	//Using same as Brutallus for now, need to find actual spell id

class LadySacrolashAI : public ArcScriptBossAI
{
    ARCSCRIPT_FACTORY_FUNCTION(LadySacrolashAI, ArcScriptBossAI);
	LadySacrolashAI(Creature* pCreature) : ArcScriptBossAI(pCreature)
	{
		AddSpell(LADY_SACROLASH_DARK_TOUCHED, Target_RandomPlayerApplyAura, 50, 0, 10, 0, 50);
		AddSpell(LADY_SACROLASH_SHADOW_BLADES, Target_Current, 25, 1.5, 5, 0, 50);
		AddSpell(LADY_SACROLASH_SHADOW_NOVA, Target_RandomPlayer, 15, 3.5, 20, 0, 50, false, "Shadow to the aid of fire!");
		AddSpell(LADY_SACROLASH_CONFOUNDING_BLOW, Target_RandomPlayer, 10, 0, 15, 0, 50);
		SetEnrageInfo(AddSpell(LADY_SACROLASH_ENRAGE, Target_Self, 0, 0, 0, 0, 0, 0, "Time is a luxury you no longer possess!"), 360000);

		//Emotes
		AddEmote(Event_OnTargetDied, "Shadows, engulf!", Text_Yell);
		AddEmote(Event_OnDied, "I... fade.", Text_Yell);
	}

	void OnCombatStart(Unit* pTarget)
	{
		mGrandWarlockAlythess = GetNearestCreature(CN_GRAND_WARLOCK_ALYTHESS);
		ParentClass::OnCombatStart(pTarget);
	}

	void OnDied(Unit* pKiller)
	{
		if( mGrandWarlockAlythess && mGrandWarlockAlythess->IsAlive() )
		{
			mGrandWarlockAlythess->Emote("Sacrolash!", Text_Yell);
		}
		ParentClass::OnDied(pKiller);
	}

	ArcScriptCreatureAI* mGrandWarlockAlythess;
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Grand Warlock Alythess
#define GRAND_WARLOCK_ALYTHESS_PYROGENICS		45230
#define GRAND_WARLOCK_ALYTHESS_FLAME_TOUCHED	45348
#define GRAND_WARLOCK_ALYTHESS_CONFLAGRATION	45342
#define GRAND_WARLOCK_ALYTHESS_BLAZE			45235
#define GRAND_WARLOCK_ALYTHESS_FLAME_SEAR		46771
#define GRAND_WARLOCK_ALYTHESS_ENRAGE			26662	//Using same as Brutallus for now, need to find actual spell id

class GrandWarlockAlythessAI : public ArcScriptBossAI
{
    ARCSCRIPT_FACTORY_FUNCTION(GrandWarlockAlythessAI, ArcScriptBossAI);
	GrandWarlockAlythessAI(Creature* pCreature) : ArcScriptBossAI(pCreature)
	{
		AddSpell(GRAND_WARLOCK_ALYTHESS_PYROGENICS, Target_Self, 100, 0, 10, 0, 50);
		AddSpell(GRAND_WARLOCK_ALYTHESS_FLAME_TOUCHED, Target_RandomPlayerApplyAura, 10, 0, 30, 0, 50);
		AddSpell(GRAND_WARLOCK_ALYTHESS_CONFLAGRATION, Target_RandomPlayer, 15, 3.5, 25, 0, 50, false, "Fire to the aid of shadow!");
		AddSpell(GRAND_WARLOCK_ALYTHESS_BLAZE, Target_RandomPlayer, 30, 2.5, 0, 0, 50);
		AddSpell(GRAND_WARLOCK_ALYTHESS_FLAME_SEAR, Target_RandomPlayer, 20, 0, 0, 0, 50);
		SetEnrageInfo(AddSpell(GRAND_WARLOCK_ALYTHESS_ENRAGE, Target_Self, 0, 0, 0, 0, 0, false, "Your luck has run its course!"), 360000);

		//Emotes
		AddEmote(Event_OnTargetDied, "Fire, consume!", Text_Yell);
		AddEmote(Event_OnDied, "I... fade.", Text_Yell);
	}

	void OnCombatStart(Unit* pTarget)
	{
		mLadySacrolash = GetNearestCreature(CN_LADY_SACROLASH);
		ParentClass::OnCombatStart(pTarget);
	}

	void OnDied(Unit* pKiller)
	{
		if( mLadySacrolash && mLadySacrolash->IsAlive() )
		{
			mLadySacrolash->Emote("Alythess! Your fire burns within me!", Text_Yell);
		}
		ParentClass::OnDied(pKiller);
	}

	ArcScriptCreatureAI* mLadySacrolash;
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//M'uru
#define CN_MURU						25741
#define CN_SHADOWSWORD_BERSERKER	25798
#define CN_SHADOWSWORD_FURY_MAGE	25799
#define CN_VOID_SENTINEL			25772
#define MURU_NEGATIVE_ENERGY		46008	//patch 2.4.2: this spell shouldn't cause casting pushback (to be fixed in core)
#define MURU_DARKNESS				45996
#define MURU_SUMMON_BERSERKER		46037
#define MURU_SUMMON_FURY_MAGE		46038
#define MURU_SUMMON_VOID_SENTINEL	45988

class MuruAI : public ArcScriptBossAI
{
    ARCSCRIPT_FACTORY_FUNCTION(MuruAI, ArcScriptBossAI);
	MuruAI(Creature* pCreature) : ArcScriptBossAI(pCreature)
	{
		AddSpell(MURU_NEGATIVE_ENERGY, Target_Self, 25, 0, 0);
		AddSpell(MURU_DARKNESS, Target_Self, 20, 0, 45);

		//AddSpell(MURU_SUMMON_BERSERKER, Target_, 15, 3.5, 25, 0, 50);  Most of Databases don't the SQL for this yet. Also I am not sure what function are for summoning Spells :).
		//AddSpell(MURU_SUMMON_FURY_MAGE, Target_, 30, 2.5, 0, 0, 50);
		//AddSpell(MURU_SUMMON_VOID_SENTINEL, Target_, 20, 0, 0, 0, 50);
	}
};

class ShadowswordBerserkerAI : public ArcScriptCreatureAI
{
    ARCSCRIPT_FACTORY_FUNCTION(ShadowswordBerserkerAI, ArcScriptCreatureAI);
	ShadowswordBerserkerAI(Creature* pCreature) : ArcScriptCreatureAI(pCreature){}
};

class ShadowswordFuryMageAI : public ArcScriptCreatureAI
{
    ARCSCRIPT_FACTORY_FUNCTION(ShadowswordFuryMageAI, ArcScriptCreatureAI);
	ShadowswordFuryMageAI(Creature* pCreature) : ArcScriptCreatureAI(pCreature){}
};

class VoidSentinelAI : public ArcScriptCreatureAI
{
    ARCSCRIPT_FACTORY_FUNCTION(VoidSentinelAI, ArcScriptCreatureAI);
	VoidSentinelAI(Creature* pCreature) : ArcScriptCreatureAI(pCreature){}
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//Entropius
#define CN_ENTROPIUS				25840
#define ENTROPIUS_NEGATIVE_ENERGY	46289 //SpellID taken from Wowhead
#define ENTROPIUS_BLACK_HOLE		46282 //SpellID taken from Wowhead

class EntropiusAI : public ArcScriptBossAI
{
    ARCSCRIPT_FACTORY_FUNCTION(EntropiusAI, ArcScriptBossAI);
	EntropiusAI(Creature* pCreature) : ArcScriptBossAI(pCreature)
	{
		//AddSpell(ENTROPIUS_NEGATIVE_ENERGY, Target_Self, 15, 0, 0, 0, 0); //Needs Testing
		//AddSpell(ENTROPIUS_BLACK_HOLE, Target_Self, 10, 0, 0, 0, 0); //Needs Testing
	}
};

//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#define CN_VOLATILE_FELFIRE_FIEND 25603
#define CN_HAND_OF_THE_DECEIVER 25588
#define FELFIRE_FISSION 45779
#define SHADOW_BOLT_VOLLEY 45770
#define SHADOW_INFUSION 45772
#define ANVEENA_PRISON 46367
#define FELFIRE_PORTAL 46875

class HandOfTheDeceiverAI : public ArcScriptBossAI
{
    ARCSCRIPT_FACTORY_FUNCTION(HandOfTheDeceiverAI, ArcScriptBossAI);
	HandOfTheDeceiverAI(Creature* pCreature) : ArcScriptBossAI(pCreature)
	{
		AddSpell(FELFIRE_PORTAL, Target_RandomPlayer, 40, 0, 10, 0, 30);
		AddSpell(SHADOW_BOLT_VOLLEY, Target_Current, 60, 0, 8, 0, 30);
	}

	void OnCombatStart(Unit* mTarget)
    {
		ParentClass::OnCombatStart(mTarget);
    }

	void OnLoad()
	{
		ParentClass::OnLoad();
	}

	void AIUpdate()
	{
		if(GetHealthPercent()<=25)
		{
			ApplyAura(SHADOW_INFUSION);
		}
		ParentClass::AIUpdate();
	}

	void OnDied(Unit * mKiller)
	{
		Despawn(10000,0);
		ParentClass::OnDied(mKiller);
	}
	
};

#define CN_SHIELD_ORB 25502
#define SHIELD_ORB_SHADOWBOLT 45680

//Kil'Jeaden
#define CN_KILJAEDEN 25315

//phase 2
#define SOUL_FLAY 45442
#define LEGION_LIGHTNING 45664
#define FIRE_BLOOM 45641
//phase 3
#define SINISTER_REFLECTION 45892
#define SHADOW_SPIKE 45885
#define FLAME_DART_EXPLOSION 45746
#define DARKNESS_OF_A_THOUSAND_SOULS 45657
//phase 4
#define CN_ARMAGEDDON 25735
//phase 5
#define SACRIFICE_OF_ANVEENA 46474

class KilJaedenAI : public ArcScriptBossAI
{
	ARCSCRIPT_FACTORY_FUNCTION(KilJaedenAI, ArcScriptBossAI);
	KilJaedenAI(Creature* pCreature) : ArcScriptBossAI(pCreature)
	{
		AddPhaseSpell(1, AddSpell(LEGION_LIGHTNING, Target_RandomPlayer, 10, 2.0f, 3, 0, 35));
		AddPhaseSpell(1, AddSpell(SOUL_FLAY, Target_RandomPlayer, 10, 2.5f, 3, 0, 35));
		AddPhaseSpell(1, AddSpell(FIRE_BLOOM, Target_RandomPlayer, 10, 1.3f, 15, 0, 35));

	}

	void OnLoad()
	{
		HandOfTheDeceiver1 = _unit->GetMapMgr()->GetInterface()->SpawnCreature(CN_HAND_OF_THE_DECEIVER, 1678.00f, 610.00f, 28.00f, 0.00f, true, false, 0, 0);
		HandOfTheDeceiver2 = _unit->GetMapMgr()->GetInterface()->SpawnCreature(CN_HAND_OF_THE_DECEIVER, 1712.00f, 604.00f, 28.00f, 0.00f, true, false, 0, 0);
		HandOfTheDeceiver3 = _unit->GetMapMgr()->GetInterface()->SpawnCreature(CN_HAND_OF_THE_DECEIVER, 1684.00f, 651.00f, 28.00f, 0.00f, true, false, 0, 0);
		HandOfTheDeceiver4 = _unit->GetMapMgr()->GetInterface()->SpawnCreature(CN_HAND_OF_THE_DECEIVER, 1720.00f, 642.00f, 28.00f, 0.00f, true, false, 0, 0);	
		_unit->SetUInt64Value(UNIT_FIELD_FLAGS, ( false ) ? 0 : UNIT_FLAG_NOT_ATTACKABLE_9);
		_unit->GetAIInterface()->SetAllowedToEnterCombat(false);
		SetCanMove(false);
		ShShadowbolt = dbcSpell.LookupEntry(SHIELD_ORB_SHADOWBOLT);
		Darkness_explosion = dbcSpell.LookupEntry(29973);
		Darkness = dbcSpell.LookupEntry(DARKNESS_OF_A_THOUSAND_SOULS);
		ApplyAura(46367);
		ApplyAura(46410);
		StopMovement();
		ParentClass::OnLoad();
	}

	void OnCombatStart(Unit* mTarget)
	{
		SetAllowMelee(false);
		SetCanMove(false);
		dtimmer = 1;
		ParentClass::OnCombatStart(mTarget);
	}

	void OnDied(Unit * mKiller)
	{
		ParentClass::OnDied(mKiller);
	}

	void AIUpdate()
	{
		if ((HandOfTheDeceiver1 && HandOfTheDeceiver2 && HandOfTheDeceiver3 && HandOfTheDeceiver4) && (HandOfTheDeceiver1->IsDead() || HandOfTheDeceiver2->IsDead() || HandOfTheDeceiver3->IsDead() || HandOfTheDeceiver4->IsDead()) && (GetPhase() != 1))
		{
			RemoveAura(46410);
		}

		if ((HandOfTheDeceiver1 && HandOfTheDeceiver2 && HandOfTheDeceiver3 && HandOfTheDeceiver4) && (HandOfTheDeceiver1->IsDead() && HandOfTheDeceiver2->IsDead() && HandOfTheDeceiver3->IsDead() && HandOfTheDeceiver4->IsDead()) && (GetPhase() != 1) && (GetPhase() != 2))
		{
			SetPhase(1);
			_unit->SetUInt64Value(UNIT_FIELD_FLAGS, ( true ) ? 0 : UNIT_FLAG_NOT_ATTACKABLE_9);
			_unit->GetAIInterface()->SetAllowedToEnterCombat(true);
			RemoveAura(46367);
			ShieldOrb1 = _unit->GetMapMgr()->GetInterface()->SpawnGameObject(CN_SHIELD_ORB, 1678.00f, 610.00f, 28.00f, 0.00f, false, 0, 0);
		}

		if (ShieldOrb1)
		{
			//ShieldOrb1->CastSpell(ShShadowbolt);
		}
		if (ShieldOrb2)
		{
			//ShieldOrb2->CastSpell(ShShadowbolt);
		}
		if (ShieldOrb3)
		{
			//ShieldOrb3->CastSpell(ShShadowbolt);
		}
		if (ShieldOrb4)
		{
			//ShieldOrb4->CastSpell(ShShadowbolt);
		}

		switch (dtimmer)
		{
		case 100:
			{
				dtimmer++;
				if (GetHealthPercent()<=85)
				{
					SetPhase(2);
					SetAllowMelee(false);
					SetCanMove(false);
					_unit->SendChatMessage(CHAT_MSG_MONSTER_YELL, LANG_UNIVERSAL, "Kil'jaeden begins to channel dark energy");
				}
			}break;
		case 120:
			{
				dtimmer++;
				if (GetPhase() == 2)
					CastSpellOnTarget(_unit, Target_RandomPlayer, Darkness_explosion, true);
					//CastSpellOnTarget(_unit, Target_RandomPlayer, Darkness, true); //this is the correct, but the dragon doesn't work.
				SetAllowMelee(false);
				SetCanMove(false);
			}break;
		case 128:
			{
				SetPhase(1);
				SetAllowMelee(false);
				SetCanMove(false);
				dtimmer = 1;
			}break;
		default:
			{
				SetCanMove(false);
				SetAllowMelee(false);
				dtimmer++;
			}break;
		}

		switch(GetPhase())
		{
		case 1:
			{
				if(GetHealthPercent()<=85)
				{
					AddPhaseSpell(1, AddSpell(SINISTER_REFLECTION, Target_RandomPlayer, 10, 1.5f, 4, 0, 35));
					AddPhaseSpell(1, AddSpell(SHADOW_SPIKE, Target_RandomDestination, 10, 2.0f, 6, 0, 35));
					AddPhaseSpell(1, AddSpell(FLAME_DART_EXPLOSION, Target_RandomPlayer, 10, 1.3f, 4, 0, 35));
					ShieldOrb1 = _unit->GetMapMgr()->GetInterface()->SpawnGameObject(CN_SHIELD_ORB, 1678.00f, 610.00f, 28.00f, -1.72788f, false, 0, 0);
				}

				if(GetHealthPercent()<=55)
				{
					ShieldOrb1 = _unit->GetMapMgr()->GetInterface()->SpawnGameObject(CN_SHIELD_ORB, 1684.00f, 651.00f, 28.00f, 0.00f, false, 0, 0);
				}

				if(GetHealthPercent()<=25)
				{
					//armageddon
					ShieldOrb1 = _unit->GetMapMgr()->GetInterface()->SpawnGameObject(CN_SHIELD_ORB, 1720.00f, 642.00f, 28.00f, 0.00f, false, 0, 0);
					AddPhaseSpell(1, AddSpell(SACRIFICE_OF_ANVEENA, Target_RandomPlayer, 50, 0.5f, 10, 0, 35));
				}
			}break;
		}
		ParentClass::AIUpdate();
	}

protected:
	Unit *HandOfTheDeceiver1;
	Unit *HandOfTheDeceiver2;
	Unit *HandOfTheDeceiver3;
	Unit *HandOfTheDeceiver4;
	GameObject* ShieldOrb1;
	GameObject* ShieldOrb2;
	GameObject* ShieldOrb3;
	GameObject* ShieldOrb4;
	SpellEntry *Darkness_explosion;
	SpellEntry *Darkness;
	SpellEntry *ShShadowbolt;
	int dtimmer;
};

void SetupSunwellPlateau(ScriptMgr* pScriptMgr)
{
	pScriptMgr->register_creature_script(CN_SUNBLADE_PROTECTOR, &SunbladeProtectorAI::Create);

	pScriptMgr->register_creature_script(CN_KALECGOS, &KalecgosAI::Create);
	pScriptMgr->register_creature_script(CN_SATHROVARR_THE_CORRUPTOR, &SathrovarrTheCorruptorAI::Create);
	pScriptMgr->register_creature_script(CN_BRUTALLUS, &BrutallusAI::Create);
	pScriptMgr->register_creature_script(CN_FELMYST, &FelmystAI::Create);
	pScriptMgr->register_creature_script(CN_LADY_SACROLASH, &LadySacrolashAI::Create);
	pScriptMgr->register_creature_script(CN_GRAND_WARLOCK_ALYTHESS, &GrandWarlockAlythessAI::Create);
	pScriptMgr->register_creature_script(CN_MURU, &MuruAI::Create);
	pScriptMgr->register_creature_script(CN_SHADOWSWORD_BERSERKER, &ShadowswordBerserkerAI::Create);
	pScriptMgr->register_creature_script(CN_SHADOWSWORD_FURY_MAGE, &ShadowswordFuryMageAI::Create);
	pScriptMgr->register_creature_script(CN_VOID_SENTINEL, &VoidSentinelAI::Create);
	pScriptMgr->register_creature_script(CN_ENTROPIUS, &EntropiusAI::Create);
	pScriptMgr->register_creature_script(CN_KILJAEDEN, &KilJaedenAI::Create);
	pScriptMgr->register_creature_script(CN_HAND_OF_THE_DECEIVER, &HandOfTheDeceiverAI::Create);
}