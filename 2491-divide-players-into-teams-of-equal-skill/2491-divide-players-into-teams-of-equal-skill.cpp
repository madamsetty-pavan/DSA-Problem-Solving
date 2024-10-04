class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        vector<long long> freq(1001,0);
        long long n = skill.size();
        long long sumTotal = 0;
        for(int i=0; i < n; i++) {
            freq[skill[i]]++;
            sumTotal += skill[i];
        }
        if(sumTotal % (n/2) !=0) return -1;
        long long requiredSum = sumTotal/(n/2), totalChemistry = 0;
        for(int i=0;i<n;i++) {
            if(freq[skill[i]] == 0) continue;
            long long partnerSkill = requiredSum - skill[i];
            if(freq[skill[i]]>0 && partnerSkill>=0 && freq[partnerSkill]<=0) return -1;
            freq[partnerSkill]--;
            freq[skill[i]]--;
            totalChemistry += (partnerSkill * skill[i]);
        }
        return totalChemistry;
    }
};