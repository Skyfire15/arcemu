ALTER TABLE `charters` DROP KEY `leaderGuid`, ADD UNIQUE KEY `leaderGuid` (`charterType`,`leaderGuid`);