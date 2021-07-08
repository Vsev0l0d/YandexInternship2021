const module = {};

module.exports = function (input) {
    const participants = input.participants;
    const sports = input.sports;
    /**
     * Подобно оператору new создает экземпляр объекта,
     * используя функцию-конструктор и параметры для нее
     */
    function constructFrom (fnConstructor, ...params) {
        const res = {};
        fnConstructor.apply(res, params);
        Object.setPrototypeOf(res, fnConstructor);
        return res;
    }

    /**
     * Создает пары вида [’вид спорта’, ’имя участника’],
     * где первому виду спорта соответствует последний участник
     */
    function assignParicipants() {
        const participants = this.participants;
        const sports = this.sports;
        const res = [];

        let i = sports.length;
        while (i--) {
            res.push([sports[participants.length - i - 1], participants[i]]);
        }

        return res;
    }

    function Contest(participants, sports) {
        this.participants = participants;
        this.sports = sports;
    }

    Contest.assignParicipants = assignParicipants;
    const contest = constructFrom(Contest, participants, sports);
    return contest.assignParicipants();
}

console.log(module.exports({ participants: [ 'Mary', 'Kate' ], sports: [ 'football', 'hockey' ] }));