#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define SHIFT 3

char substring[100];

void set_substring(const char *string, int StartPos, int EndPos) {
    if (EndPos < StartPos) {
        fprintf(stderr, "Error: End position must be greater than Start Position\n");
        return;
    }

    if (strlen(string) < StartPos || strlen(string) < EndPos) {
        printf("Error: position not defined in provided string.\n");
        return;
    }

    string += StartPos;

    int shift = EndPos - StartPos;

    int i;
    for (i = 0; i <= shift; i++) {
        substring[i] = string[i];
    }
    substring[i] = '\0';
}

void print_substring() {
    printf("\nsubstring: %s", substring);
}

int substring_contains_duplicated() {
    int contains = 0;
    for (int i = 0; i < strlen(substring); i++) {
        for (int j = i + 1; j < strlen(substring); j++) {
            if (substring[i] == substring[j]) {
                contains = 1;
                break;
            }
        }
    }

    return contains;
}

int start_of_packet(char *string) {
    int shift = 3, start = 3;

    for (int s = 0, e = shift; e < strlen(string); s++, e++) {
        set_substring(string, s, e);

        if (substring_contains_duplicated() == 0) {
            start = e;
            break;
        }
    }

    return start + 1;
}

int start_of_message(char *string) {
    int shift = 13, start = 13;

    for (int s = 0, e = shift; e < strlen(string); s++, e++) {
        set_substring(string, s, e);

        if (substring_contains_duplicated() == 0) {
            start = e;
            break;
        }
    }

    return start + 1;
}

int main() {
    printf("%d", start_of_message("vmsvstvtzvzqvzvssvddsgdddrqrsqqwnnffrwrswwztwzzbssgtstvsshrsrrlvrvzrrsqsvqsqbssqrsrjrsrddqnnfqnnrfnrnffjsjnnqddjjbvvbzzshhsffmtftrrpzznlltclltmltmllzclcwwgzzzqvqhqllcrllqdqpqnqbqggcrcsclssrfsssqhhfzzprrjvrjvvblvbllwccztzggspgggqrqcqjcqjcqcmmffmtmltlwwcpplpqqwhwvhvnnqhqsqlqvvgfgqqddlhhstthzhgzgbzbdzbzlzwlzlpljlgjjqlltrrbmrrvvcttsddfjddmbdbffcrfftvvzppncpcvcdvcvvjjjlttcgtcctrrrgmrgmgwwsgscsffswfwqwnnzmzffpwptpntppbddggsbsddmjmssnzsnstsztttjztjjpddwlwrrlnnzsnnfllqrrqmqhhfddtmmpfmfcfgfllngnvnjjmffwbffsqsmsdstdddjssmlssfpprrgzzzwvvftffczfftccwrrdsrsjrssfnsnttqptqtnqtnqtttjqtjqjzjpzpvzvbzvvjqqvcqcwwgwllbwbjjhsjhhchffgdfgffvddrndrdwdwlwqqfqzzntzzhwzzndnjnsjjmvvlqqqqshhmzzjvvcscqqjjhphnppcprrhnnbsspcscbssnsmmznzsnnszsrzrwrswsgwglwlzznpnwpnnjlnlrnntllhvvdrvvprpptqqlzqzrrgfgfhfvhhcscjjfmmjpmjjvwvtvhvqhqvvqvwvpvsschhlmlrlmljjqnqggbwbmwbwgbwwgllqzllrjlrjjfjzffthhpvvsddvjvvzsvvhghlhqqbnqqlnngsngnccnpccmttmrtmmlmccqbbjssbsqbqddnqqdvdvbvgbvvjfjhjzzfhfzffgccdjcjtjpttcrrffvddwgglrgllbttcqtctqtvtwtggrppzvvbzvzgzsznnsqnsqqnwwzrwwnwbwnnhznhzhchwwvwhwlwlnnmwmfmfrmmnvndnffjgjmgmfmhmtmstthjhbjhjddrqrllnflnnwzwjjthjhwhmmflmlfmfddqgdqgqqwbbdsstssrvvbpbgppfwfvvglvvzgvgmvgvzvdvcctddjqddffrprbrggpgpghhwzhzggqrqsrstrssnttrgrsswsrstsdtdzttzvznzjnzzqssjwswcswsgghqghqgqvggtsswwmbbfrrdcctjtjsttrccqbbtcctcscqsssvmmdhmdmvdmvmsvsrvsrvsszvvrpvrpprvppctclcrrchhtmmbddswddglgrrdcdppcbpbgpbggbssnrnbrbllqwqbwbmmcwmmrjrdjjpsjppblbjbsbsgswsmwmgwgmmqpplzlssvcscnngwgvvffvlvtvtddgqgttjljggfzggmfgfqqtrrdbdbbnjnnbjbwwjjqljlnjjvzvhvlhhhsfhsfscsjcjsjbsjjdbdbpbqqsggcnczcchrhjhphlppnwwhthghhfvfrrbzrbrrcsszfmhrjflswthfrlmjbnhblmsldjpnrdgfbcrftnbcltlctbdthhjzsqvbmppcbhctqbtfhdrtrbzjpnzzvtfjtpqgbtmdcnjgtblhmvrpbrcpqfhpzqvbfqhsrjqwqqnggrlgvwndqrhvpzhswnglngwjdgwcnngrvhtcsblpdshqcwfpzcpmrbzqjfpllbbvlcfjtdqchjsgsqgqzsbfnnqcsvpwfmzdhzmcjfjnczldclvpfpntppqbhfqzqdtfwsvdzhphwpzhqqfflswhtldlrmrqpfdlwwszphrwjqvhpqmrzvblvtvsfpgzdhnlmsgpqnqdtbjqccbtnvqmtdggdsvvfwjzbdpnztmsblpgcrmppblmtfnjvjwmhnwqdmdrvbvsvhgbhjwzjfcqzwtvzlfmpzvpwsdsqphmqlzwfrqdjdbsmfdzllqqfhmcmhchjpbqtjbczhbcllmtqgczdfnjsjhhcsfdhwwbzzjdqtlvgfgfwbqztqftfqhsfvbzjcbmtdzszfsgzpqpvtqnmjhlrtbvfphvhwbnqsnwgpznnwcbbvdqvvzllqpjbqhqwtfzlhqgvmrpjmlvczqgmffsjvgzvnvccgnmdmbcqjqvbnzvdgnbdwbszldjwjdsnplgqnjmlvrlzcvlgtrdndhjmrtczqjqrzzzclrdmdmrgvljstqfhldfzgvhcdtmncqjjnghgwdgnhbjztfgpqnvfhzngqcftpbqsnvgrqpczwptghbssljnftzmbrqmnbvcbsshvmmmczjgnbjwltflndtntmfznmqhzjjtmmtwbflhmqcmlmzrnvfqzmzhhszqmmqwgzcnncjwvdzvczsgbpcscjptfpwhvvvstvqzhtptrmbhttcrdzhljpmclrbnzmvmtbmmdhfgpjjwsldsgdjflhmfrgvmgzvntgmlglfsntpjjwgnpwsjvsnbctwlsqvprlfmsqfdmzdsdvbtsnqzflvtlgrmdhfgfmwrcqjvbwqsblnwlmtqfhdwwlchqljbljwzmmqgqpwfnmjlvhmppzsdjlbvqwmwqwqqsrgzmpzzzzstrtrbwttzjcmlssstpntnrwtgthrfmthbjjmmtcvjnwsdpdndccgncjbjdqbwtlbfcmgvmlbrdzzlzcpctjvldbpvvmsrwrhhtdsrwljtmntcftwvppjvtttgslrdvpglzdnhrgnrzjsczsmtcfclhvncrhsfvbppqrbwsmjbhjmllwwlqvhbljrqpzshqvllzqtjfhdlnghwblzjldcmfgfjgcbfwqldvdppjmsqqqmznwtcgpmlpqmdpzctwjpnstvgjsbzspfbvfcrgzzcdbzfthgbjrnjwpprblnhdcfgpdcmljpqqzchslpvlwqjvsqtnvnfjhpvwjnjzghnbslhmrhwdppgtvzzmhzzzsvldphjlhrfjwrctfcmnzpvvwqrczcsmznflcwzsplrsdvmfghmnbbjdzclnzpbtjllcszzjcqbbczqhbnfpcctbmhfglsdtnzdjrjbjqczqflznfwzsrmpcgvgrjmhtpgllcpdnlrzvqljprnpvcglvmbtbzjwqfrhdngwsrfjsqnhfncnvprrcngjzfdvcnphcchbqhqpbbbzgmbfndlffnrpzvplptnrvjlzfczvsbctmdqrzdnpvrtgnsgdjwqshglspdzbhflfbsfvbrqgfzmhzhshdlcnqhzbnhbhmsgffgsmvglhscqsrsvmszjfgdhsglbqgwwjndscsqvpccwhlvjbtvftdppcscjblwtmpvvchpzwmblmbbrrvwlglfqwtgcffnzljnmtpbcrszvblwfqdslpqlrmnvrhvrzwnprnmntzrpsdcnwfgljldpvjwwzzbpcltnvghqvqnvmmrfqsnbstdctqqgtpzqttnrrdstrtlfzmvvbzzwwchrscqlnpzdmphdwdqdwbszlhwsbfscthndrdvhtgbpsmznlfjpwjchvzbmrflcphhgjfwstjnzlllztgzjmnwcglmhrbztzdnbcbrgrlmpprrbthbhslfrsjsrrrqvwmqghcgdvvsmrqdwwbdnzmnsqfflpbbjvzjdgsfjdjmbhptmrnbqpqhcdwtvbdlrdzsrchqlsrccjfbfrnnrctdsqbnjzzvrlcwphsscppdmsbrqrzddrdvjwfrldccmzwrhrbpcqpnvnbgpsrhvbchmrdtwqrlvpwhqgnppmsdvqdldlrjrzntlsfwmwhjsghddsppchqlltrhlwrccvflwjbvptclqvwdmrmghbngbflfspsjmglzcqjdtdtldmmngljwfqvfwnmfdtrsmlqzszhzccgvbnnwtpbgssrcqlqgrsjqfhhwpvdtsclgsntwvcsfpvwfqnmwhmtldfswqrsvzshfzwlnwhqhwsrqqzlsdhvqfwnhjcvmplcljmlhbtqtrpjfjfdfmlhtfpnszptfnjbldscjgvjhpzflhm"));
    return 0;
}
