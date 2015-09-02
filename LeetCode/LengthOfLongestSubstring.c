/**
Given a string, find the length of the longest substring without repeating characters.
For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3.
For "bbbbb" the longest substring is "b", with the length of 1.
**/

#include <stdlib.h>
int hash[256][2];

int lengthOfLongestSubstring(char* s) {
    if(!s)
        return 0;
    int len = 0, newLen = 0;
    int it = 1;

    int hashIndex = 0;
    int stringIndex = 0;

    memset(hash, 0, sizeof(int)*256*2);
    while(*(s+stringIndex))
    {
        hashIndex = *(s+stringIndex);
        if(hash[hashIndex][1]==it)//本次迭代遇到重复字母，进行下次迭代
        {
            len = len>newLen?len:newLen;//更新最长长度
            newLen = 0;
            stringIndex = hash[hashIndex][2]+1;//下一次迭代起始位置为重复字母的下一个
            it++;//迭代次数增一
        }
        else
        {
            newLen++;
            hash[hashIndex][1] = it;
            hash[hashIndex][2] = stringIndex;
            stringIndex++;
        }
    }
    return len>newLen?len:newLen;//更新最长长度
}

int lengthOfLongestSubstringOn(char* s) {
    if(!s)
        return 0;
    int len = 0, newLen = 0;
    int it = 1;

    int hashIndex = 0;
    int stringIndex = 0;

    int newStart = 0;

    memset(hash, 0, sizeof(int)*256*2);
    while(*(s+stringIndex))
    {
        hashIndex = *(s+stringIndex);
        if(hash[hashIndex][1]==it)//本次迭代遇到重复字母，进行下次迭代
        {
            len = len>newLen?len:newLen;//更新最长长度

            newLen = stringIndex-hash[hashIndex][2]-1;//直接求得当前新长度，不用回退，下面一行注释掉
            //stringIndex = hash[hashIndex][2]+1;//下一次迭代起始位置为重复字母的下一个
            it++;//迭代次数增一
            //更新新串迭代次数
            for(newStart=hash[hashIndex][2]+1; newStart<stringIndex; newStart++){
                hash[*(s+newStart)][1] = it;
            }
        }
        else
        {
            newLen++;
            hash[hashIndex][1] = it;
            hash[hashIndex][2] = stringIndex;
            stringIndex++;
        }
    }
    return len>newLen?len:newLen;//更新最长长度
}

int lengthOfLongestSubstringOn2(char* s) {
    if(!s)
        return 0;
    int len = 0, newLen = 0;

    char existed[256];
    memset(existed, 0, sizeof(char)*256);

    int start = 0;
    int end = 0;

    char endC = *(s+end);
    char startC = *(s+start);

    while(endC)
    {
        if(existed[endC])//遇到重复字符
        {
            newLen = end-start;
            len = len>newLen?len:newLen;//更新最长长度

            while( startC != endC ){
                existed[startC] = 0;
                start++;
                startC = *(s+start);
            }
            existed[startC] = 0;
            start++;
            startC = *(s+start);
        }
        existed[endC] = 1;
        end++;
        endC = *(s+end);
    }
    newLen = end-start;
    return len>newLen?len:newLen;//更新最长长度
}

//测试
void lengthOfLongestSubstringMain(void)
{
    char s[] = //"bba";
    //"abcdabbcdegbb";
    //"lengthOfLongestSubstringMain";
    //"lengthOfLongehashIndexstSubstlengthhashInhashIndexdexOfLohashIndexngestSubstringlehashIndexngthOfLongestSubstringOnringlengthOfLongestSubstringOn";
    //"Given a string, find the length of the longest substring without repeating characters";
    "Given a string, find the length of the longest substring without repeating characters.\
For example, the longest substring without repeating letters for bcabcbb is abc, which the length is 3.\
For bbbbb the longest substring is b, with the length of 1.";
    //"Diatoms are heterokont unicellular algae with a widespread distribution throughout all\
     aquatic habitats. Research on diatoms has advanced significantly over the last decade due to\
      available genetic transformation methods and publicly available genome databases. Yet up to now, \
      proteins involved in the regulation of the cytoskeleton in diatoms are largely unknown. Consequently, \
      this work focuses on actin and actin-related proteins (ARPs) encoded in the diatom genomes of Thalassiosira \
      pseudonana, Thalassiosira oceanica, Phaeodactylum tricornutum, Fragilariopsis cylindrus and Pseudo-nitzschia\
       multiseries. Our comparative genomic study revealed that most diatoms possess only a single conventional actin \
       and a small set of ARPs. Among these are the highly conserved cytoplasmic Arp1 protein and the nuclear Arp4 as \
       well as Arp6. Diatom genomes contain genes coding for two structurally different homologues of Arp4 that might \
       serve specific functions. All diatom species examined here lack ARP2 and ARP3 proteins, suggesting that diatoms\
        are not capable of forming the Arp2/3 complex, which is essential in most eukaryotes for actin filament branch\
        ing and plus-end dynamics. Interestingly, none of the sequenced representatives of the Bacillariophyta phylum \
        code for profilin. Profilin is an essential actin-binding protein regulating the monomer actin pool and is i\
        nvolved in filament plus-end dynamics. This is the first report of organisms not containing profilin.\
        Cell biologists have been intrigued by diatoms for more than a century, primarily due to their beautifully ornamented silica cell walls (Lauterborn, 1896, Reimann, 1964, Li and Volcani, 1985 and Pickett-Heaps et al., 1990). However, even with such a long history of cell biological research on diatoms, very little is known about the dynamics and regulation of the cytoskeleton. There is currently no information on the presence or absence of cytoskeletal proteins except for actin, tubulin, dynein and myosin (Pickett-Heaps, 1991, Poulsen et al., 1999, Wickstead and Gull, 2007 and Heintzelman and Enriquez, 2010). Actin is one of the most highly conserved and abundant proteins in eukaryotic cells and a major component of the cytoskeleton (Dominguez and Holmes, 2011). Dynamic assembly and disassembly of the actin cytoskeleton are essential for many cellular functions such as cell motility, the control of cell shape and polarity, cytokinesis, intracellular transport, as well as endo- and exocytosis (Pollard et al., 2000 and Blanchoin et al., 2014). Although research about the diatom cytoskeleton is progressing (Edgar and Pickett-Heaps, 1984, Poulsen et al., 1999, De Martino et al., 2009, Heintzelman and Enriquez, 2010 and Tesson and Hildebrand, 2010b), we are far from understanding the organization and dynamics of the cytoskeleton.\
\
The diatom actin cytoskeleton is highly organized with a fine cortical actin meshwork and an extensive network spanning the cytoplasm (Aumeier et al., in preparation). Apart from its role in fundamental cellular processes it is involved in some unique diatom-specific processes (Edgar and Pickett-Heaps, 1984 and Van de Meene and Pickett-Heaps, 2002). In raphid pennate diatoms two thick actin bundles parallel to the raphe are important for generating their unique type of gliding motion (Edgar and Pickett-Heaps, 1984 and Poulsen et al., 1999). In centrics and pennates an actin ring at the leading edge of the silica deposition vesicle during cell wall morphogenesis has been observed (Van de Meene and Pickett-Heaps, 2004 and Tesson and Hildebrand, 2010b). The involvement of the actin cytoskeleton in cell wall morphogenesis has been proposed on the basis of ultrastructural and actin-staining studies combined with drug treatments (Pickett-Heaps and Kowalski, 1981, Schmid, 1984, Schmid, 1987, Schmid, 1994, Cohn et al., 1989, Pickett-Heaps et al., 1990, Van de Meene and Pickett-Heaps, 2002, Van de Meene and Pickett-Heaps, 2004, Kröger and Poulsen, 2008, Tesson and Hildebrand, 2010a and Tesson and Hildebrand, 2010b). Even with structural information available about the actin cytoskeleton in diatoms it is not reported, how the actin network is regulated and which actin-related, actin-binding and actin-interacting proteins are encoded within the diatom genomes.\
\
The structure and dynamics of the actin cytoskeleton are largely dependent on and tightly regulated by actin-binding proteins which assist in nucleation, polymerization/de-polymerization, bundling, fragmentation as well as branching of the actin filament (Cooper and Schafer, 2000, Pollard et al., 2000, Condeelis, 2001, Pollard and Borisy, 2003, Blanchoin et al., 2010 and Blanchoin et al., 2014). Among the over 100 proteins that interact with actin are the so-called actin-related proteins (ARPs). The members in this family are structurally very similar to actin, numbered according to their decreasing homology with actin (Arp1 to Arp11); Arp1 is structurally most closely related to actin and Arp11 the most divergent from actin (Poch and Winsor, 1997). The ARPs can be grouped into cytoplasmic ARPs (Arp1-3 and Arp10–11) and nuclear ARPs (Arp4–9). Regardless of their cellular location, ARPs are often found as homopolymers or heteropolymers, and assemble with additional proteins into large multiprotein complexes that are frequently associated with actin (Schafer and Schroer, 1999). Nuclear ARPs are important in the context of gene transcription as well as chromosomal organization (Schafer and Schroer, 1999 and Kast and Dominguez, 2011). The cytoplasmic ARPs have different functions, the Arp2/3 complex, together with half a dozen other proteins, has been known for more than a decade as the molecular key player in actin filament branching and plus-end filament nucleation (Mullins et al., 1998, Beltzner and Pollard, 2008 and Volkmann et al., 2014). The other cytoplasmic multiprotein machinery involving ARPs is the Arp1- and Arp11-containing dynactin complex, which activates and targets a microtubule dependent dynein activity (Schafer and Schroer, 1999). Despite the importance and variety of the ARP family, ARPs have so far only been described for T. pseudonana in a board screening throughout the eukaryotic phyla ( Muller et al., 2005).\
\
Continuous subunit turnover is essential for the dynamics and plasticity of the actin cytoskeleton in order to allow rapid remodelling in response to internal and external signals. Cellular processes such as cell motility, control of cell polarity and cytokinesis are driven by finely tuned actin polymerization, which requires the availability of a suitably sized pool of ATP-actin. Profilin is well known to accelerate the rate of ADP to ATP exchange in globular (G)-actin (Mockrin and Korn, 1980, Goldschmidt-Clermont et al., 1991, Korenbaum et al., 1998 and Yarmola and Bubb, 2006) and binds to G-actin at a molar ratio of 1:1 (Schutt et al., 1993 and Vinson and Archer, 1993). However, in plants and algae profilin totally lacks the nucleotide exchange activity but nevertheless it is still an essential protein for actin regulation in these organisms (Kovar et al., 2000 and Kovar et al., 2001). The present analysis revealed that diatoms apparently do not encode profilin within their genomes; therefore raising the question of how diatoms can do without it.\
In recent years, a considerable amount of genome and transcriptome data have become publicly available for a number of diatom species. Complete genome sequences are available for two representatives of the centric diatoms, Thalassiosira pseudonana ( Armbrust et al., 2004) and Thalassiosira oceanica ( Lommer et al., 2012) and three pennate diatoms Phaeodactylum tricornutum ( Bowler et al., 2008), Fragilariopsis cylindrus and Pseudo-nitzschia multiseries at the Joint Genome Institute (JGI) ( Nordberg et al., 2014). Given the fact that other Stramenopile genomes have meanwhile also been sequenced and are publicly available e.g.: Aurantiochytrium limacinum, Schizochytrium aggregatum, Aplanochytrium kerguelense, Phytophthora sojae, Aureococcus anophagefferens ( Gobler et al., 2011), at JGI ( Nordberg et al., 2014) as well as Ectocarpus siliculosus ( Sterck et al., 2012), a large resource of genome information is providing excellent opportunities to perform in silico comparative genome analyses. By drawing from these resources, this work presents results of a genome analysis of cytoskeletal proteins in diatoms, starting here with the gene family of actin-related proteins including actin and the actin monomer-binding protein profilin.\
Organism specialized sequence databases of the Joint Genome Institute (www.jgi.doe.gov/), the Blastocystis Genome Browser (www.genoscope.cns.fr/externe/GenomeBrowser/ Blastocystis/), the Toxoplasma Genomics Resource (http://toxodb.org/toxo-release4-0/home.jsp) and the On-line Resource for Community Annotation of Eukaryotes (http://bioinformatics.psb.ugent.be/orcae/overview/Ectsi) were accessed for comprehensive genome and protein BLAST searches for following the Stramenopiles: T.pseudonana, P.tricornutum, F.cylindrus, P. multiseries, A.limacinum, S.aggregatum, A.kerguelense, P.sojae, Phytophthora infestans, A.anophagefferens, and E.siliculosus. The protein sequences of T. oceanica were retrieved through NCBI and HMMER search tools (hmmsearch) (http://hmmer.janelia.org/).\
Up to 15 protein sequences representing major taxa including mammals, fish, plants, flies, amphibia, worms, fungi, and heterokonts were used to screen for actin, Arp1 to Arp11 and profilin in the databases described above. Additional diatom sequences were retrieved using bioinformatic search tools such as BLAST (blstp, tblastn, blastn, blastx) at NCBI (nr database), and Profile hidden Markov models (HMMER) (http://hmmer. janelia.org/). PSI-BLAST and HMMER search tools (hmmsearch) were used to confirm the absence of profilin in diatoms. All obtained sequences were blasted against the NCBI database (www.ncbi.nlm.nih.gov/), aligned and manually corrected to determine the protein sequence.\
The above candidate actin, ARP and profilin (Supplementary Table A1) were compared with a larger repertoire of actins, ARPs and profilin from a variety of eukaryotes retrieved from NCBI, UniProtKB (http://www.uniprot.org/uniprot/) and the Protein Data Bank (PDB) (www.rcsb.org/pdb/home/home.do). All sequences were aligned with the Clustal Omega, MAFFT, or MUSCLE software from EBI (www.ebi.ac.uk/Tools/ msa/clustalo/) using pairwise parameters set at default settings. Aligned candidate ARP sequences were screened for the describing signatures of the ARP subfamilies. The identification and clustering of the ARP proteins into the ARP subfamilies were further verified through the Actin Related Proteins Annotation server (ARPAnno) (Muller et al., 2005).";
    printf("%d\n", lengthOfLongestSubstring(s));
    printf("%d\n", lengthOfLongestSubstringOn(s));
    printf("%d\n", lengthOfLongestSubstringOn2(s));
}
