node: IP*
add_to_ignore: RP|FP|X|PUNC|REP
define: Defs.def
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
yes: (IP* iDoms DO[DI]|DOP*) AND (DO[DI]|DOP* hasSister VB|DO|HV|BE)
hv: (IP* iDoms HV[DI]|HVP*)
be: (IP* iDoms BE[DI]|BEP*)
md:  (IP* iDoms aux) AND (aux hasSister nonfin)
no:  (IP* iDoms finV|VBI|DOI|HVI)
}

// verb-raising above negation?
4: {
fin-neg: (IP* iDoms finV) AND (NEG hasSister finV) AND (finV precedes NEG) //finV includes aux
neg-fin: (IP* iDoms finV) AND (NEG hasSister finV) AND (NEG precedes finV)
}
// type of subject
5: {
plNP: (IP* iDoms NP-SBJ*PL)
  //pronouns
\2p: (IP* iDoms NP-SBJ*NSR) AND (NP-SBJ* idoms PRO-*)  AND (PRO-* idomslast 2PRO)
\3sg: (IP* iDoms NP-SBJ*) AND (NP-SBJ* idoms PRO-*)  AND (PRO-* idomslast 3sgPRO)
\1sg: (IP* iDoms NP-SBJ*NSR) AND (NP-SBJ* idoms PRO-*)  AND (PRO-* idomslast 1sgPRO)
\1sg: (IP* iDoms NP-SBJ*) AND (NP-SBJ* idoms PRO-*)  AND (PRO-* idomsonly 1sgPRO)
\3sg: (IP* iDoms NP-SBJ*) AND (NP-SBJ* idoms PRO-*)  AND (PRO-* idomsonly 3sgPRO)
\2p: (IP* iDoms NP-SBJ*) AND (NP-SBJ* idoms PRO-*)  AND (PRO-* idomsonly 2PRO)
pl:   (IP* iDoms NP-SBJ*) AND (NP-SBJ* idoms PRO-*) AND (PRO-* idomsonly plPRO)
//null subjects
conNSR: (IP* iDoms NP-SBJ*NSR) AND (NP-SBJ*NSR idoms \*con\*)
conNO: (IP* iDoms NP-SBJ*NO) AND (NP-SBJ*NO idoms \*con\*)
//conPL: (IP* iDoms NP-SBJ*PL) AND (NP-SBJ*PL idoms \*con\*)
nullSBJ: (IP* iDoms NP-SBJ*) AND (NP-SBJ* idoms \**)
//full NP
plNP: (IP* iDoms NP-SBJ*) AND (NP-SBJ* idoms NS)
NP:   (IP* iDoms NP-SBJ*)
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

//adjacency
7: {
inv: (IP* iDoms finV|MD) AND (finV|MD hassister NP-SBJ*) AND (finV|MD iprecedes NP-SBJ*)
null-adj:   (IP* iDoms NP-SBJ*) AND (NP-SBJ* idoms PRO-*) AND (PRO-* hassister CONJ|*P*|RRC) AND (CONJ|*P*|RRC idoms \**)
weak-adj: (IP* iDoms NP-SBJ*) AND (NP-SBJ* iprecedes finV|MD) AND (NP-SBJ* idomslast Q*|ADV*|NUM*|CONJ)
adj: (IP* iDoms NP-SBJ*) AND (NP-SBJ* idomslast PRO-*) AND (NP-SBJ* iprecedes finV|MD)
adj: (IP* iDoms NP-SBJ*) AND (NP-SBJ* hassister finV|MD) AND (NP-SBJ* idomslast N|NS|NPR) AND (NP-SBJ* iprecedes finV|MD)
no-adj: (IP* iDoms NP-SBJ*) AND (NP-SBJ* hassister finV|MD) AND (NP-SBJ* idomsfirst PRO-*) AND (PRO-* hassister CONJ|*P*|RRC) AND (NP-SBJ* iprecedes finV|MD)
no-adj: (IP* iDoms NP-SBJ*) AND (NP-SBJ* hassister finV|MD) AND (NP-SBJ* idomslast !N|NS|NPR) AND (NP-SBJ* idoms CONJ|*P*|RRC) AND (NP-SBJ* iprecedes finV|MD)
no-adj: (IP* iDoms NP-SBJ*) AND (NP-SBJ* idoms \**) AND (NP-SBJ* iprecedes finV|MD)
no-adj: (IP* iDoms NP-SBJ*) AND (NP-SBJ* idoms \**)
adj: (IP* iDoms NP-SBJ*) AND (NP-SBJ* hassister finV|MD) AND (NP-SBJ* iprecedes finV|MD)
weak-adj: (IP* iDoms NP-SBJ*) AND (NP-SBJ* hassister finV|MD) AND (NP-SBJ* iPrecedes ADVP*|NEG) AND (ADVP*|NEG iPrecedes finV|MD)
no-adj: ELSE
}

//inflection?
8: {
infl: (IP* iDoms VBP-s|DOP-s|HVP-s|BEP-s)
no-infl: (IP* iDoms VB[DIP]|DO[DIP]|HV[DIP]|BE[DIP])
modal: (IP* iDoms MD)
}

// know-class
9: {
k-class: (IP* idoms VB|VBP*|VBD) AND (VB|VBP*|VBD idoms KNOW|DOUBT|TROW|FEAR|HOPE|DESIRE|THINK)
other: ELSE
}
