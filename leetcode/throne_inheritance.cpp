class Ruler {
public:
    string name;
    vector<Ruler*> children;
    bool alive;

    Ruler(string name) {
        this->name = name;
        this->alive = true;
    }
};

class ThroneInheritance {
private:
    Ruler* root = NULL;
    map<string, Ruler*> rulerObjMap;
public:
    ThroneInheritance(string kingName) {
        root = new Ruler(kingName);
        rulerObjMap.insert({kingName, root});
    }

    void birth(string parentName, string childName) {
        Ruler* child = new Ruler(childName);
        rulerObjMap.insert({childName, child});
        rulerObjMap[parentName]->children.push_back(child);
    }

    void death(string name) {
        rulerObjMap[name]->alive = false;
    }

    vector<string> getInheritanceOrder() {
        Ruler* iter = root;
        vector<string> res;
        fetchInheritanceForRuler(iter, res);
        return res;
    }

    void fetchInheritanceForRuler(Ruler* ruler, vector<string>& res) {
        if(ruler == NULL) return;
        else {
            if(ruler->alive) res.push_back(ruler->name);
            for(Ruler* child: ruler->children) {
                fetchInheritanceForRuler(child, res);
            }
        }
    }

};