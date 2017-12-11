
public class Packet {
  public:
    const int source;
    const int destination;
    const int flowID;
    const int sequenceNumber;
  
    Packet(int source, int destination, int flowID, int sequenceNumber) {
      this->source = source;
      this->destination = destination;
      this->flowID = flowID;
      this->sequenceNumber = sequenceNumber;
    }
}
