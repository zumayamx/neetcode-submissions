struct PageNode {
    string url;
    PageNode* prev = nullptr;
    PageNode* next = nullptr;

    PageNode(string x) { url = x; }
};

class BrowserHistory {
    PageNode* currPage = nullptr;

   private:
    void deleteForward(PageNode* node) {
        PageNode* nextNode = node->next != nullptr ? node->next : nullptr;

        while (node != nullptr) {
            delete (node);
            node = nextNode;
            nextNode = node != nullptr && node->next != nullptr ? node->next : nullptr;
        }
    }

   public:
    BrowserHistory(string homepage) {
        PageNode* visitPage = new PageNode(homepage);
        currPage = visitPage;
    }

    void visit(string url) {
        PageNode* visitPage = new PageNode(url);

        if (currPage->next != nullptr) deleteForward(currPage->next);
        currPage->next = visitPage;
        currPage->next->prev = currPage;
        currPage = visitPage;
    }

    string back(int steps) {
        while (steps > 0 && currPage->prev != nullptr) {
            currPage = currPage->prev;
            steps--;
        }

        return currPage->url;
    }

    string forward(int steps) {
        while (steps > 0 && currPage->next != nullptr) {
            currPage = currPage->next;
            steps--;
        }

        return currPage->url;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */