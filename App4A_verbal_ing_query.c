node: IP-PPL*|NP*
add_to_ignore: RP|FP|X|PUNC|REP
define: gerund_defs.def
coding_query:

// verb or noun
1: {
hybrid: (NP*hyb idoms NP-COM)
hybrid: ([1]IP-PPL* iDoms gerundV) AND (NP*hyb idoms [1]IP-PPL*)
verb:  ([1]IP-PPL* iDoms gerundV) AND (PP* idoms [1]IP-PPL*)
verb: (IP-PPL* isroot) AND (IP-PPL* idoms gerundV)
verb: (IP-PPL* idoms gerundV)
noun: (NP* iDoms N|NS) AND (N|NS iDoms noun-gerund)
none: ELSE
}

// object?
2: {
//nominal object
N: (NP*hyb idoms NP-COM)
N: (IP-PPL* idoms gerundV) AND (IP-PPL* idoms NP-OB1*|NP-OB2*)
//clausal object
clause: (NP* iDoms N|NS) AND (N|NS iDoms noun-gerund) AND (N|NS hassister IP-INF*|CP-THT*|CP-QUE*)
clause: (IP-PPL* idoms gerundV) AND (IP-PPL* idoms IP-INF*|CP-THT*|CP-QUE*)
//adjective predicate
adjp: (NP* iDoms N|NS) AND (N|NS idoms noun-gerund) AND (N|NS hassister ADJP) AND (N|NS precedes ADJP)
adjp: (IP-PPL* idoms gerundV) AND (IP-PPL* idoms ADJP)
//PP complement
PPof: (NP* iDoms N|NS) AND (N|NS idoms noun-gerund) AND (N|NS hassister PP) AND (PP idomsmod P of|off)
PP: (NP* iDoms N|NS) AND (N|NS idoms noun-gerund) AND (N|NS hassister PP*)
PP: (IP-PPL* idoms gerundV) AND (IP-PPL* idoms PP*)
none: (IP-PPL* idomslast gerundV)
none: (NP* idomslast N|NS) AND (N|NS idoms noun-gerund)
no: ELSE
}

// ending?
3: {
//verbs/hybrids
and: (IP-PPL* idoms gerundV) AND (gerundV idoms nd-gerund)
ing: (IP-PPL* idoms gerundV) AND (gerundV idoms ing-gerund)
//nouns
ing: (NP* iDoms N|NS) AND (N|NS idoms noun-gerund)
other: ELSE
}

//function
4: {
//hybrid
sbj: ([1]IP-PPL* iDoms gerundV) AND (NP-SBJ*hyb iDoms [1]IP-PPL*)
sbj: (NP-SBJ*hyb iDoms noun-gerund) AND (NP-SBJ*hyb idoms NP-COM)
obj: ([1]IP-PPL* iDoms gerundV) AND (NP-OB*hyb iDoms [1]IP-PPL*)
obj: (NP-OB*hyb iDoms noun-gerund) AND (NP-OB*hyb idoms NP-COM)
//nouns
sbj: (NP-SBJ* iDoms N|NS) AND (N|NS iDoms noun-gerund)
obj: (NP-OB* iDoms N|NS) AND (N|NS iDoms noun-gerund)
//verbs
sbj: (IP-PPL-SBJ* iDoms gerundV)
obj: (IP-PPL-OB* idoms gerundV)
// adjuncts?
adjunct: (IP-PPL* idoms gerundV) AND (IP-PPL* hassister finV|gerundV|impV|infin)
adjunct: (IP-PPL* idoms gerundV) AND (IP-PPL* hassister N|NS|NPR|Q|NUM|OTHER|OTHERS|PRO-*) AND (!D|*$|NP-POS iprecedes IP-PPL*)
adjunct: (IP-PPL-ABS idoms gerundV)
root: (IP-PPL* isroot) AND (IP-PPL* idoms gerundV)
//exclude
conj: (IP-PPL* idoms gerundV) AND (IP-PPL* hassister CONJ*)
conj: (NP* idoms N|NS) AND (NP* hassister CONJ*)
adj-comp: (NP* idoms N|NS) AND (NP* hassister ADJ)
other: (IP-PPL* idoms gerundV) AND (IP-PPL* hassister C)
//complements of P
Pcomp: (NP*hyb idoms N|NS) AND (N|NS idoms noun-gerund)
Pcomp: (NP* idoms N|NS) AND (N|NS idoms noun-gerund)
Pcomp: (NP*hyb idoms IP-PPL*) AND (IP-PPL* idoms gerundV)
Pcomp: (IP-PPL* idoms gerundV) AND (IP-PPL* hassister D|*$|NP-POS) AND (D|*$|NP-POS iprecedes IP-PPL*)
Pcomp: (IP-PPL* idoms gerundV) AND (IP-PPL* hassister P)
//assuming everything else is a free adjunct
adjunct: (IP-PPL* idoms gerundV)
}

// modal
5: {
modal: (IP-PPL* iDoms HAG|BAG|DAG) AND (HAG|BAG|DAG hassister VAN|VBN|DAN|DON|BEN|HAN|HVN)
}

//pre-N (for hybrids and nouns)
6: {
//determiners
det: (IP-PPL* iDoms gerundV) AND (IP-PPL* hassister D)
det: (NP* idoms N|NS) AND (N|NS hassister D)
//possessives
pos: (IP-PPL* iDoms gerundV) AND (IP-PPL* hassister *$|NP-POS)
pos: (NP* idoms N|NS) AND (N|NS hassister *$|NP-POS)
//other
indef: (IP-PPL* iDoms gerundV) AND (IP-PPL* hassister ONE|Q|NUM)
indef: (NP* idoms N|NS) AND (N|NS hassister ONE|Q|NUM)
bare: ELSE
}

//adverbs and neg
7: {
loc_temp: (IP-PPL* iDoms gerundV) AND (gerundV hassister *LOC|*TMP|*DIR)
loc_temp: (NP* iDoms N|NS) AND (N|NS hassister *LOC|*TMP|*DIR)
adv: (IP-PPL* iDoms gerundV) AND (gerundV hassister ADV*)
adv: (NP* iDoms N|NS) AND (N|NS hassister ADV*)
neg: (IP-PPL* iDoms gerundV) AND (gerundV hassister NEG*)
neg: (NP* iDoms N|NS) AND (N|NS hassister NEG*)
}
