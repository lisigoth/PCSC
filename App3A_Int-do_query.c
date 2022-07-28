node: IP*
add_to_ignore: RP|FP|X|PUNC|REP
define: Ecay_defs.def
coding_query:

// polarity
1: {
neg: (IP* iDoms NEG)
aff: ELSE
}

// mood
2: {
imp: (IP* iDoms VBI|DOI|BEI|HVI)
decl: ELSE
}

// do-support?
3: {
do: (IP* iDoms DO[DI]|DOP*) AND (DO[DI]|DOP* hasSister VB|DO|HV|BE)
hv: (IP* iDoms HV[DI]|HVP*) AND (HV[DI]|HVP* hassister nonfin)
be: (IP* iDoms BE[DI]|BEP*)
md:  (IP* iDoms MD) AND (aux hasSister nonfin)
lex:  (IP* iDoms finV|VBI|DOI|HVI)
}

// verb-raising above negation?
4: {
fin-neg: (IP* iDoms finV) AND (NEG hasSister finV) AND (finV precedes NEG) //finV includes aux
neg-fin: (IP* iDoms finV) AND (NEG hasSister finV) AND (NEG precedes finV)
}
// type of subject
5: {
  //pronouns
pro: (IP* iDoms NP-SBJ*) AND (NP-SBJ* idoms PRO-*)
//null subjects
nullSBJ: (IP* iDoms NP-SBJ*) AND (NP-SBJ* idoms \**)
//full NP
NP:   (IP* iDoms NP-SBJ*)
else: ELSE
}

// tense/mood
6: {
// main verb is nonfinite
present: (IP* iDoms DOP*|VBP*|HVP*|BEP*) AND (DOP*|VBP*|HVP*|BEP* hassister nonfin)
past:    (IP* iDoms DOD|VBD|HVD|BED) AND (DOD|VBD|HVD|BED hassister nonfin)
imp:     (IP* iDoms DOI|VBI|HVI|BEI) AND (DOI|VBI|HVI|BEI hassister nonfin)
modal:   (IP* iDoms MD) AND (MD hasSister VB|DO|HV|BE)
// main verb is finite
present: (IP* iDoms DOP*|VBP*|HVP*|BEP*)
past:    (IP* iDoms DOD|VBD|HVD|BED)
imp:     (IP* iDoms DOI|VBI|HVI|BEI)
}

//adv position
7: {
adv-V: (IP* iDoms NP-SBJ*) AND (NP-SBJ* hassister finV) AND (NP-SBJ* iPrecedes ADVP*) AND (ADVP* iPrecedes finV|MD)
V-adv: (IP* iDoms NP-SBJ*) AND (NP-SBJ* hassister finV) AND (finV iPrecedes ADVP*)
no-adv: (IP* idoms !ADVP)
}

//verb class
8: {
//ellegard/exp
KNOW: (IP* idoms VB|VBP*|VBD) AND (VB|VBP*|VBD idoms KNOW)
DOUBT: (IP* idoms VB|VBP*|VBD) AND (VB|VBP*|VBD idoms DOUBT)
TROW: (IP* idoms VB|VBP*|VBD) AND (VB|VBP*|VBD idoms TROW)
FEAR: (IP* idoms VB|VBP*|VBD) AND (VB|VBP*|VBD idoms FEAR)
HOPE: (IP* idoms VB|VBP*|VBD) AND (VB|VBP*|VBD idoms HOPE)
DESIRE: (IP* idoms VB|VBP*|VBD) AND (VB|VBP*|VBD idoms DESIRE)
THINK: (IP* idoms VB|VBP*|VBD) AND (VB|VBP*|VBD idoms THINK)
//agentive
SEND: (IP* idoms VB|VBP*|VBD) AND (VB|VBP*|VBD idoms SEND)
SAY: (IP* idoms VB|VBP*|VBD) AND (VB|VBP*|VBD idoms SAY)
GIVE: (IP* idoms VB|VBP*|VBD) AND (VB|VBP*|VBD idoms GIVE)
WRITE: (IP* idoms VB|VBP*|VBD) AND (VB|VBP*|VBD idoms WRITE)
TAKE: (IP* idoms VB|VBP*|VBD) AND (VB|VBP*|VBD idoms TAKE)
MAKE: (IP* idoms VB|VBP*|VBD) AND (VB|VBP*|VBD idoms MAKE)
//unacc
GO: (IP* idoms VB|VBP*|VBD) AND (VB|VBP*|VBD idoms GO)
COME: (IP* idoms VB|VBP*|VBD) AND (VB|VBP*|VBD idoms COME)
FALL: (IP* idoms VB|VBP*|VBD) AND (VB|VBP*|VBD idoms FALL)
STAND: (IP* idoms VB|VBP*|VBD) AND (VB|VBP*|VBD idoms STAND)
LIE: (IP* idoms VB|VBP*|VBD) AND (VB|VBP*|VBD idoms LIE)
STAY: (IP* idoms VB|VBP*|VBD) AND (VB|VBP*|VBD idoms STAY)
LIVE: (IP* idoms VB|VBP*|VBD) AND (VB|VBP*|VBD idoms LIVE)
//lexical do (agentive)
lexDO: (IP* idoms DOP*|DOD) AND (DOP*|DOD idoms lexDO) AND (DOP*|DOD hassister !VB|DO|HV|BE)
lexDO: (IP* idoms DO) AND (DO idoms lexDO) AND (DO hassister DOP*|DOD)
}

//verb category
9: {
ell: (IP* idoms VB|VBP*|VBD) AND (VB|VBP*|VBD idoms KNOW|DOUBT|TROW|FEAR)
k-class: (IP* idoms VB|VBP*|VBD) AND (VB|VBP*|VBD idoms HOPE|DESIRE|THINK)
ag: (IP* idoms DOP*|DOD) AND (DOP*|DOD idoms lexDO) AND (DOP*|DOD hassister !VB|DO|HV|BE)
ag: (IP* idoms VB|VBP*|VBD) AND (VB|VBP*|VBD idoms SEND|SAY|GIVE|WRITE|TAKE|MAKE)
unacc: (IP* idoms VB|VBP*|VBD) AND (VB|VBP*|VBD idoms GO|COME|FALL|STAND|LIE|STAY|LIVE)
ag: (IP* idoms DO) AND (DO idoms lexDO) AND (DO hassister DOP*|DOD)
}
