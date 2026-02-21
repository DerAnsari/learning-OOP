#include <iostream>
#include <string>
using std::string, std::cout, std::endl, std::cin;

struct Player {
  int ID;
  string Name;
  int lvl;
  string type;
  int arrivalOrder;
};

struct playerNode {
  Player Data;
  playerNode *Next;
  playerNode *Prev;
  playerNode(Player data) : Data(data), Next(nullptr), Prev(nullptr) {}
};

struct undoNode {
  string Command;
  Player playerRecord;
  int boostAmmout;
  undoNode *Next;
};

class linkedList {
private:
  playerNode *head;
  playerNode *tail;

public:
  linkedList() : head(nullptr), tail(nullptr) {}

  // to be used when dealing with normal queue
  void pushBack(Player data) {
    playerNode *newNode = new playerNode(data);
    if (tail == nullptr) {
      head = tail = newNode;
    } else {
      tail->Next = newNode;
      tail = newNode;
    }
  }

  // to be used when dealing with vip queue
  void priorityInsert(Player p) {
    playerNode *newNode = new playerNode(p);

    if (head == nullptr || p.lvl > head->Data.lvl ||
        (p.lvl == head->Data.lvl && p.arrivalOrder < head->Data.arrivalOrder)) {
      newNode->Next = head;
      if (head != nullptr)
        head->Prev = newNode;
      head = newNode;
      if (tail == nullptr)
        tail = newNode;
      return;
    }

    playerNode *currNode = head;
    while (currNode->Next != nullptr) {
      if (p.lvl > currNode->Data.lvl)
        break;

      if (p.lvl == currNode->Next->Data.lvl &&
          p.arrivalOrder < currNode->Next->Data.arrivalOrder)
        break;

      currNode = currNode->Next;
    }

    newNode->Next = currNode->Next;
    newNode->Prev = currNode;

    if (currNode->Next != nullptr) {
      currNode->Next->Prev = newNode;
    } else {
      tail = newNode;
    }
    currNode->Next = newNode;
  }

  Player popFront() {
    if (isEmpty()) {
      throw std::runtime_error("Queue is empty");
    } else {
      Player data = head->Data;
      playerNode *temp = head;
      head = head->Next;
      if (head)
        head->Prev = nullptr;
      else
        tail = nullptr;
      delete temp;
      return data;
    }
  }

  // helpers
  void removebyID(int id) {
    playerNode *temp = head;
    while (temp != nullptr) {
      if (temp->Data.ID == id) {
        if (temp->Prev)
          temp->Prev->Next = temp->Next;
        else
          head = temp->Next;

        if (temp->Next)
          temp->Next->Prev = temp->Prev;
        else
          tail = temp->Prev;

        delete temp;
        return;
      }
      temp = temp->Next;
    }
  }

  int getSize() {
    int count = 0;
    playerNode *temp = head;
    while (temp != nullptr) {
      count++;
      temp = temp->Next;
    }
    return count;
  }
  bool isEmpty() { return head == nullptr; }

  void display() {
    playerNode *temp = head;
    while (temp != nullptr) {
      cout << temp->Data.Name << endl;
      temp = temp->Next;
    }
  }

  Player findbyID(int id) {
    playerNode *temp = head;
    while (temp != nullptr) {
      if (temp->Data.ID == id)
        return temp->Data;
      temp = temp->Next;
    }
    return Player{-1, "", 0, "", 0};
  }
};

class undoStack {
private:
  undoNode *top;

public:
  undoStack() : top(nullptr) {}

  void push(string command, Player playerRecord, int boostAmmout) {
    undoNode *newNode = new undoNode{command, playerRecord, boostAmmout};
    newNode->Next = top;
    top = newNode;
  }

  undoNode *pop() {
    if (top == nullptr)
      return nullptr;
    undoNode *temp = top;
    top = top->Next;
    return temp;
  }

  bool isEmpty() { return top == nullptr; }
};

class tournamentManager {
private:
  linkedList normalQueue;
  linkedList vipQueue;
  undoStack history;
  int arrivalOrderCount{0};

public:
  void Register(int id, string name, int lvl, string typ) {
    if (normalQueue.findbyID(id).ID == -1 && vipQueue.findbyID(id).ID == -1) {
      Player newPlayer = Player{id, name, lvl, typ, arrivalOrderCount};
      if (newPlayer.type == "Normal")
        normalQueue.pushBack(newPlayer);
      else
        vipQueue.priorityInsert(newPlayer);
      history.push("REGISTER", newPlayer, 0);
      arrivalOrderCount++;
    }
  };

  void play() {
    if (vipQueue.isEmpty() && normalQueue.isEmpty()) {
      cout << "NO PLAYERS";
      return;
    }

    Player p;
    if (!vipQueue.isEmpty()) {
      p = vipQueue.popFront();
    } else {
      p = normalQueue.popFront();
    }

    cout << p.ID << " " << p.Name << endl;
    history.push("PLAY", p, 0);
  }

  void boost(int id, int x) {
    Player p = vipQueue.findbyID(id);
    if (id == vipQueue.findbyID(id).ID) {
      vipQueue.removebyID(id);
      p.lvl += x;
      vipQueue.priorityInsert(p);

      history.push("BOOST", p, x);
    }
  }

  void withdraw(int id) {
    if (normalQueue.findbyID(id).ID == id) {
      Player p = normalQueue.findbyID(id);
      normalQueue.removebyID(id);
      history.push("WITHDRAW", p, 0);
    } else if (vipQueue.findbyID(id).ID == id) {
      Player p = vipQueue.findbyID(id);
      vipQueue.removebyID(id);
      history.push("WITHDRAW", p, 0);
    }
  }

  void undo() {
    undoNode *lastAction = history.pop();
    if (lastAction == nullptr)
      return;

    string cmd = lastAction->Command;
    Player p = lastAction->playerRecord;

    if (cmd == "REGISTER") {
      if (p.type == "VIP")
        vipQueue.removebyID(p.ID);
      else
        normalQueue.removebyID(p.ID);
    } else if (cmd == "PLAY" || cmd == "WITHDRAW") {
      if (p.type == "VIP")
        vipQueue.priorityInsert(p);
      else
        normalQueue.pushBack(p);
    } else if (cmd == "BOOST") {
      vipQueue.removebyID(p.ID);
      p.lvl -= lastAction->boostAmmout;
      vipQueue.priorityInsert(p);
    }

    delete lastAction;
  }

  void status() {
    cout << vipQueue.getSize() << " " << normalQueue.getSize() << endl;
    cout << "VIP Waiting Area" << endl;
    vipQueue.display();
    cout << "Normal Waiting Area" << endl;
    normalQueue.display();
  }
};

int main() {
  tournamentManager manager;
  int Q;

  // Read number of operations
  if (!(std::cin >> Q))
    return 0;

  while (Q--) {
    string cmd;
    cin >> cmd;

    if (cmd == "REGISTER") {
      int id, lvl;
      string name, type;
      cin >> id >> name >> lvl >> type;
      manager.Register(id, name, lvl, type);
    } else if (cmd == "PLAY") {
      manager.play();
    } else if (cmd == "BOOST") {
      int id, x;
      cin >> id >> x;
      manager.boost(id, x);
    } else if (cmd == "WITHDRAW") {
      int id;
      cin >> id;
      manager.withdraw(id);
    } else if (cmd == "UNDO") {
      manager.undo();
    } else if (cmd == "STATUS") {
      manager.status();
    }
  }

  return 0;
}
